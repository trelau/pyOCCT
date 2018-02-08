from distutils.core import setup

setup(
        name='OCCT',
        version='0.0.1',
        packages=['OCCT'],
        package_data={'OCCT': ['*.pyd', '*.dll']},
        author='Laughlin Research, LLC',
        author_email='info@laughlinresearch.com',
        description='Python bindings to OpenCASCADE.',
        license='LGPL v2.1',
        platforms=['Windows']
)
