from distutils.core import setup

setup(
        name='OCCT',
        version='0.0.1',
        packages=['OCCT'],
        package_data={'OCCT': ['*.pyd', '*.dll']},
        author='Laughlin Research, LLC',
        author_email='info@laughlinresearch.com',
        dsescription='Python bindings to OpenCASCADE.',
        license='Proprietary',
        zip_safe=False,
        platforms=['Windows']
)
