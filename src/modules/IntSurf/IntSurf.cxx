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

void bind_IntSurf_TypeTrans(py::module &);
void bind_IntSurf_Situation(py::module &);
void bind_IntSurf_PntOn2S(py::module &);
void bind_IntSurf_ListOfPntOn2S(py::module &);
void bind_IntSurf_ListIteratorOfListOfPntOn2S(py::module &);
void bind_IntSurf_Transition(py::module &);
void bind_IntSurf_SequenceOfPntOn2S(py::module &);
void bind_IntSurf_Allocator(py::module &);
void bind_IntSurf_LineOn2S(py::module &);
void bind_IntSurf_Quadric(py::module &);
void bind_IntSurf_InteriorPoint(py::module &);
void bind_IntSurf_SequenceOfInteriorPoint(py::module &);
void bind_IntSurf_Couple(py::module &);
void bind_IntSurf_SequenceOfCouple(py::module &);
void bind_IntSurf_PathPoint(py::module &);
void bind_IntSurf_SequenceOfPathPoint(py::module &);
void bind_IntSurf(py::module &);
void bind_IntSurf_InteriorPointTool(py::module &);
void bind_IntSurf_PathPointTool(py::module &);
void bind_IntSurf_QuadricTool(py::module &);

PYBIND11_MODULE(IntSurf, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Adaptor3d");

bind_IntSurf_TypeTrans(mod);
bind_IntSurf_Situation(mod);
bind_IntSurf_PntOn2S(mod);
bind_IntSurf_ListOfPntOn2S(mod);
bind_IntSurf_ListIteratorOfListOfPntOn2S(mod);
bind_IntSurf_Transition(mod);
bind_IntSurf_SequenceOfPntOn2S(mod);
bind_IntSurf_Allocator(mod);
bind_IntSurf_LineOn2S(mod);
bind_IntSurf_Quadric(mod);
bind_IntSurf_InteriorPoint(mod);
bind_IntSurf_SequenceOfInteriorPoint(mod);
bind_IntSurf_Couple(mod);
bind_IntSurf_SequenceOfCouple(mod);
bind_IntSurf_PathPoint(mod);
bind_IntSurf_SequenceOfPathPoint(mod);
bind_IntSurf(mod);
bind_IntSurf_InteriorPointTool(mod);
bind_IntSurf_PathPointTool(mod);
bind_IntSurf_QuadricTool(mod);

}
