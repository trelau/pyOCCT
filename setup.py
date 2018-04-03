from setuptools import setup

setup(
    name='OCCT',
    version='0.0.1',
    packages=['OCCT', 'OCCT.Boolean', 'OCCT.Exchange', 'OCCT.Topology',
              'OCCT.Visualization'],
    package_data={'OCCT': ['*.so', '*.pyd', '*.dll',
                           'Visualization/_resources/*']},
    author='Laughlin Research, LLC',
    author_email='info@laughlinresearch.com',
    description='Python bindings for OpenCASCADE.',
    url='https://github.com/LaughlinResearch/pyOCCT',
    license='LGPL v2.1',
    platforms=['Windows', 'Linux'],
    zip_safe=False,
    classifiers=['Development Status :: 3 - Alpha',
                 'Intended Audience :: Developers',
                 'Programming Language :: Python :: 3.5']
)
