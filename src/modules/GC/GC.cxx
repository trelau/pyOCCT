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

void bind_GC_Root(py::module &);
void bind_GC_MakeArcOfCircle(py::module &);
void bind_GC_MakeArcOfEllipse(py::module &);
void bind_GC_MakeArcOfHyperbola(py::module &);
void bind_GC_MakeArcOfParabola(py::module &);
void bind_GC_MakeCircle(py::module &);
void bind_GC_MakeConicalSurface(py::module &);
void bind_GC_MakeCylindricalSurface(py::module &);
void bind_GC_MakeEllipse(py::module &);
void bind_GC_MakeHyperbola(py::module &);
void bind_GC_MakeLine(py::module &);
void bind_GC_MakeMirror(py::module &);
void bind_GC_MakePlane(py::module &);
void bind_GC_MakeRotation(py::module &);
void bind_GC_MakeScale(py::module &);
void bind_GC_MakeSegment(py::module &);
void bind_GC_MakeTranslation(py::module &);
void bind_GC_MakeTrimmedCone(py::module &);
void bind_GC_MakeTrimmedCylinder(py::module &);

PYBIND11_MODULE(GC, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gce");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");

bind_GC_Root(mod);
bind_GC_MakeArcOfCircle(mod);
bind_GC_MakeArcOfEllipse(mod);
bind_GC_MakeArcOfHyperbola(mod);
bind_GC_MakeArcOfParabola(mod);
bind_GC_MakeCircle(mod);
bind_GC_MakeConicalSurface(mod);
bind_GC_MakeCylindricalSurface(mod);
bind_GC_MakeEllipse(mod);
bind_GC_MakeHyperbola(mod);
bind_GC_MakeLine(mod);
bind_GC_MakeMirror(mod);
bind_GC_MakePlane(mod);
bind_GC_MakeRotation(mod);
bind_GC_MakeScale(mod);
bind_GC_MakeSegment(mod);
bind_GC_MakeTranslation(mod);
bind_GC_MakeTrimmedCone(mod);
bind_GC_MakeTrimmedCylinder(mod);

}
