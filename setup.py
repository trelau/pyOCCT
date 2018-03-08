from setuptools import setup

setup(
    name='OCCT',
    version='0.0.1',
    packages=['OCCT', 'OCCT.Boolean', 'OCCT.Exchange', 'OCCT.Topology',
              'OCCT.Visualization'],
    package_data={'OCCT': ['*.pyd', '*.dll', 'Visualization/_resources/*']},
    author='Laughlin Research, LLC',
    author_email='info@laughlinresearch.com',
    description='Python bindings to OpenCASCADE.',
    license='LGPL v2.1',
    platforms=['Windows']
)
