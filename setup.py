from setuptools import setup


setup(
    name='OCCT',
    version='7.5.3.0',
    packages=['OCCT', 'OCCT.Exchange', 'OCCT.Visualization'],
    package_data={'OCCT': ['*.so', '*.pyd', '*.dll', 'Visualization/_resources/*']},
    author='Trevor Laughlin',
    description='Python bindings for OpenCASCADE via pybind11.',
    url='https://github.com/trelau/pyOCCT',
    license='LGPL v2.1',
    platforms=['Windows', 'Linux']
)
