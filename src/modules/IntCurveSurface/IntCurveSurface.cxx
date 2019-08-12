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

void bind_IntCurveSurface_TransitionOnCurve(py::module &);
void bind_IntCurveSurface_IntersectionPoint(py::module &);
void bind_IntCurveSurface_SequenceOfPnt(py::module &);
void bind_IntCurveSurface_IntersectionSegment(py::module &);
void bind_IntCurveSurface_SequenceOfSeg(py::module &);
void bind_IntCurveSurface_Intersection(py::module &);
void bind_IntCurveSurface_HInter(py::module &);
void bind_IntCurveSurface_TheCSFunctionOfHInter(py::module &);
void bind_IntCurveSurface_TheExactHInter(py::module &);
void bind_IntCurveSurface_TheHCurveTool(py::module &);
void bind_IntCurveSurface_TheInterferenceOfHInter(py::module &);
void bind_IntCurveSurface_ThePolygonOfHInter(py::module &);
void bind_IntCurveSurface_ThePolygonToolOfHInter(py::module &);
void bind_IntCurveSurface_ThePolyhedronOfHInter(py::module &);
void bind_IntCurveSurface_ThePolyhedronToolOfHInter(py::module &);
void bind_IntCurveSurface_TheQuadCurvExactHInter(py::module &);
void bind_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter(py::module &);

PYBIND11_MODULE(IntCurveSurface, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.IntAna");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Intf");
py::module::import("OCCT.IntSurf");

bind_IntCurveSurface_TransitionOnCurve(mod);
bind_IntCurveSurface_IntersectionPoint(mod);
bind_IntCurveSurface_SequenceOfPnt(mod);
bind_IntCurveSurface_IntersectionSegment(mod);
bind_IntCurveSurface_SequenceOfSeg(mod);
bind_IntCurveSurface_Intersection(mod);
bind_IntCurveSurface_HInter(mod);
bind_IntCurveSurface_TheCSFunctionOfHInter(mod);
bind_IntCurveSurface_TheExactHInter(mod);
bind_IntCurveSurface_TheHCurveTool(mod);
bind_IntCurveSurface_TheInterferenceOfHInter(mod);
bind_IntCurveSurface_ThePolygonOfHInter(mod);
bind_IntCurveSurface_ThePolygonToolOfHInter(mod);
bind_IntCurveSurface_ThePolyhedronOfHInter(mod);
bind_IntCurveSurface_ThePolyhedronToolOfHInter(mod);
bind_IntCurveSurface_TheQuadCurvExactHInter(mod);
bind_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter(mod);

}
