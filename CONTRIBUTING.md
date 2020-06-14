# Contributing to pyOCCT
Thank you for your interest in contributing to pyOCCT. This document provides
a variety of hopefully helpful guidelines that will help you make the most of
your contribution. Feel free to propose changes to this document in a pull
request.

#### Contents

[Have a question?](#have-a-question?)

[Before you start](#before-you-start)

[How to contribute](#how-to-contribute)

[Styleguides](#styleguides)
 
## Have a question?
If you just have a question try the resources below before opening an issue:
 
* [pyOCCT docs](http://pyocct.readthedocs.io/en/latest/?badge=latest#)
* [Chat on Gitter](https://gitter.im/pyOCCT/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
* [OpenCASCADE forums](https://www.opencascade.com/forums)
 
## Before you start
Before getting started, you may find it helpful to review the
[Design Considerations](http://pyocct.readthedocs.io/en/latest/dev.html#design-considerations)
section of the documentation. This provides some of the assumptions and
implementation details of pyOCCT and may provide some useful background
knowledge. There is also some information regarding known issues in case you
encounter one during use.

The pyOCCT project is meant to provide Python bindings to official OpenCASCADE
releases only. Therefore, creating a fork of the OpenCASCADE library
specifically for pyOCCT will be avoided at all costs. If there is a bug or
feature request within the OpenCASCADE library the goal will be to get it fixed
and/or incorporated within the official repository.   

## How to contribute
pyOCCT is a young project so there is sure to be many areas that could use
support from contributors of all experience levels. Scanning the known issues
in the documentation and/or the "Help Wanted" section in the README may provide
a few good starting points. Providing test cases and benchmarks is another good
area to contribute towards. When you're ready, please use the resources below
to contribute:

* [Reporting bugs](https://github.com/trelau/pyOCCT/issues) The
  GitHub issues tab will be the primary way of tracking and resolving pyOCCT
  bugs. Follow the issue template and be as descriptive as possible. If the bug
  is with the OpenCASCADE C++ library, you may open a pyOCCT issue with a test
   case, but you may also consider reporting it to 
  [OpenCASCADE issue tracker](https://tracker.dev.opencascade.org/).
  
* [Feature requests](https://github.com/trelau/pyOCCT/issues) The
  GitHub issues tab will also be the primary way of tracking feature requests.
  Use the issue template again to describe the desired feature with an
  explanation of why this enhancement would be useful.
  
* [Pull requests](https://github.com/trelau/pyOCCT/pulls) The GitHub
  pull requests tab will be the primary way of merging contributions. Follow
  the pull request template. Avoid platform-dependent code.

## Styleguides
Styleguides for pyOCCT will be developed as the project matures.
