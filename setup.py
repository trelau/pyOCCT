from setuptools import setup

setup(
    name='OCCT',
    version='7.4.0.0',
    packages=['OCCT', 'OCCT.Exchange', 'OCCT.Visualization'],
    package_data={'OCCT': ['*.so', '*.pyd', '*.dll', 'Visualization/_resources/*']},
    author='Trevor Laughlin',
    description='Python bindings for OpenCASCADE.',
    url='https://github.com/LaughlinResearch/pyOCCT',
    license='LGPL v2.1',
    platforms=['Windows', 'Linux']
)
