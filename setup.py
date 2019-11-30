from setuptools import setup

setup(
    name='OCCT',
    version='7.4.0.0',
    packages=['OCCT', 'OCCT.Boolean', 'OCCT.Exchange', 'OCCT.Topology',
              'OCCT.Visualization'],
    package_data={'OCCT': ['*.so', '*.pyd', '*.dll',
                           'Visualization/_resources/*']},
    author='Laughlin Research, LLC',
    description='Python bindings for OpenCASCADE.',
    url='https://github.com/LaughlinResearch/pyOCCT',
    license='LGPL v2.1',
    platforms=['Windows', 'Linux'],
    classifiers=['Development Status :: 3 - Alpha',
                 'Intended Audience :: Developers',
                 'Programming Language :: Python']
)
