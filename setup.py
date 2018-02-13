from distutils.core import setup

setup(
        name='OCCT',
        version='0.0.1',
        packages=['OCCT', 'OCCT.Topology'],
        package_data={'OCCT': ['*.pyd', '*.dll', 'resources/icon.png']},
        author='Laughlin Research, LLC',
        author_email='info@laughlinresearch.com',
        description='Python bindings to OpenCASCADE.',
        license='LGPL v2.1',
        platforms=['Windows']
)
