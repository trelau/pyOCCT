/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>

void bind_GCE2d_Root(py::module &);
void bind_GCE2d_MakeArcOfCircle(py::module &);
void bind_GCE2d_MakeArcOfEllipse(py::module &);
void bind_GCE2d_MakeArcOfHyperbola(py::module &);
void bind_GCE2d_MakeArcOfParabola(py::module &);
void bind_GCE2d_MakeCircle(py::module &);
void bind_GCE2d_MakeEllipse(py::module &);
void bind_GCE2d_MakeHyperbola(py::module &);
void bind_GCE2d_MakeLine(py::module &);
void bind_GCE2d_MakeMirror(py::module &);
void bind_GCE2d_MakeParabola(py::module &);
void bind_GCE2d_MakeRotation(py::module &);
void bind_GCE2d_MakeScale(py::module &);
void bind_GCE2d_MakeSegment(py::module &);
void bind_GCE2d_MakeTranslation(py::module &);

PYBIND11_MODULE(GCE2d, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gce");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");

bind_GCE2d_Root(mod);
bind_GCE2d_MakeArcOfCircle(mod);
bind_GCE2d_MakeArcOfEllipse(mod);
bind_GCE2d_MakeArcOfHyperbola(mod);
bind_GCE2d_MakeArcOfParabola(mod);
bind_GCE2d_MakeCircle(mod);
bind_GCE2d_MakeEllipse(mod);
bind_GCE2d_MakeHyperbola(mod);
bind_GCE2d_MakeLine(mod);
bind_GCE2d_MakeMirror(mod);
bind_GCE2d_MakeParabola(mod);
bind_GCE2d_MakeRotation(mod);
bind_GCE2d_MakeScale(mod);
bind_GCE2d_MakeSegment(mod);
bind_GCE2d_MakeTranslation(mod);

}
