import argparse
import os
import sys

# Add the binding generator to the path
BINDER_ROOT = os.path.dirname(os.path.realpath(__file__))
PYBINDER_ROOT = os.path.join(BINDER_ROOT, 'pyOCCT_binder')
if not os.path.isdir(PYBINDER_ROOT):
    raise NotADirectoryError('Binding generator is not available.')

if PYBINDER_ROOT not in sys.path:
    sys.path.append(PYBINDER_ROOT)

from pybinder.core import Generator


def find_include_path(name, path):
    """
    Attempt to find an include directory of a given header file.

    :param name: The header file to search for.
    :param path: The starting path.

    :return: The full path to the directory of the given header file.
    """
    for root, dirs, files in os.walk(path):
        if name in files:
            return root


def gen_includes(occt_include_path, output_path):
    """
    Generate the "all_includes.h" header file for parsing the headers.

    :param str occt_include_path: The directory containing the OCCT header files.
    :param str output_path: The path to write the all_includes.h file.

    :return: All the available OCCT modules.
    :rtype: list[str]
    """

    # Generate all_includes.h and output modules
    all_includes = []

    occt_mods = set()
    for fin in os.listdir(occt_include_path):
        if fin.endswith('.hxx'):
            all_includes.append(fin)
        if '_' in fin:
            mod = fin.split('_')[0]
        else:
            mod = fin.split('.')[0]
        occt_mods.add(mod)

    # OCCT modules
    occt_mods = list(occt_mods)
    occt_mods.sort(key=str.lower)

    # Sort ignoring case
    all_includes.sort(key=str.lower)

    # all_includes.h
    with open(os.path.join(output_path, 'all_includes.h'), 'w') as fout:
        fout.write("#ifdef _WIN32\n")
        fout.write('    #include <Windows.h>\n')
        fout.write("#endif\n")

        for header in all_includes:
            fout.write('#include <{}>\n'.format(header))

    return occt_mods


def main():
    # Setup a parser
    parser = argparse.ArgumentParser()
    print('-' * 100)
    print("pyOCCT Binder")
    print('-' * 100)

    parser.add_argument(
        '-r',
        help='Root path for the pyOCCT repository',
        default='.',
        dest='pyocct_root')

    parser.add_argument(
        '-c',
        help='Path to config.txt',
        dest='config_path',
        default='config.txt')

    parser.add_argument(
        '-o',
        help='Output path for the generated bindings',
        default=os.path.join(BINDER_ROOT, 'output'),
        dest='output_path')

    args = parser.parse_args()

    # Get the root directory of the conda environment
    conda_prefix = os.environ.get('CONDA_PREFIX')

    # Attempt to find include directories by searching for a known header file. Will likely
    # need to make this more robust.
    occt_include_path = find_include_path('Standard.hxx', conda_prefix)
    vtk_include_path = find_include_path('vtk_doubleconversion.h', conda_prefix)
    tbb_include_path = find_include_path('tbb.h', conda_prefix)
    tbb_include_path = os.path.split(tbb_include_path)[0]

    print('Include directories:')
    print('\tOpenCASCADE: {}'.format(occt_include_path))
    print('\tVTK: {}'.format(vtk_include_path))
    print('\tTBB: {}'.format(tbb_include_path))

    clang_include_path = ''
    if sys.platform.startswith('linux'):
        clang_include_path = find_include_path('__stddef_max_align_t.h', conda_prefix)
        print('Found clangdev include directory: {}'.format(clang_include_path))

    if not occt_include_path or not os.path.exists(occt_include_path):
        raise NotADirectoryError("OCCT include path does not exist: {}".format(occt_include_path))

    if not os.path.exists(args.pyocct_root):
        raise NotADirectoryError("pyOCCT root path does not exist: {}".format(args.pyocct_root))

    if not os.path.exists(args.config_path):
        raise FileNotFoundError("Configuration file not found: {}".format(args.config_path))

    # Force using conda's clangdev includes. This may not be needed on other systems but was
    # getting errors on linux.
    if sys.platform.startswith('linux') and not os.path.exists(clang_include_path):
        raise NotADirectoryError("clangdev not found: {}".format(clang_include_path))

    # Gather all the includes for the parser
    other_includes = [i for i in [vtk_include_path, tbb_include_path, clang_include_path] if i]

    # Add extra includes for missing OCCT headers that cause issues during parsing
    other_includes.append(os.path.join(BINDER_ROOT, 'extra_includes'))

    print('\nGenerating all_includes.h file...')
    occt_mods = gen_includes(occt_include_path, BINDER_ROOT)

    # Initialize the main binding generation tool
    gen = Generator(occt_mods, occt_include_path, *other_includes)

    # Output bindings path
    output_path = os.path.abspath(args.output_path)
    if not os.path.exists(output_path):
        os.makedirs(output_path)
    print("\nWriting binding output files to: {}".format(output_path))

    # For debugging and dev
    gen.bind_enums = True
    gen.bind_functions = True
    gen.bind_classes = True
    gen.bind_typedefs = True
    gen.bind_class_templates = True

    # Process configuration file
    gen.process_config(args.config_path)

    print('\nParsing headers...')
    gen.parse(os.path.join(BINDER_ROOT, 'all_includes.h'))
    gen.dump_diagnostics()

    print('Traversing headers...')
    gen.traverse()

    print('Sorting binders...')
    gen.sort_binders()

    print('Building includes...')
    gen.build_includes()

    print('Building imports...')
    gen.build_imports()

    print('Checking circular imports...')
    gen.check_circular()

    print('Binding templates...')
    gen.bind_templates(output_path)

    print('Binding...')
    gen.bind(output_path)
    print('Done!')
    print('-' * 100)


if __name__ == '__main__':
    main()
