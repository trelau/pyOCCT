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

void bind_Contap_TFunction(py::module &);
void bind_Contap_IType(py::module &);
void bind_Contap_ArcFunction(py::module &);
void bind_Contap_ContAna(py::module &);
void bind_Contap_Point(py::module &);
void bind_Contap_TheSequenceOfPoint(py::module &);
void bind_Contap_TheHSequenceOfPoint(py::module &);
void bind_Contap_Line(py::module &);
void bind_Contap_TheSequenceOfLine(py::module &);
void bind_Contap_ThePathPointOfTheSearch(py::module &);
void bind_Contap_TheSegmentOfTheSearch(py::module &);
void bind_Contap_SequenceOfSegmentOfTheSearch(py::module &);
void bind_Contap_SequenceOfPathPointOfTheSearch(py::module &);
void bind_Contap_TheSearch(py::module &);
void bind_Contap_TheSearchInside(py::module &);
void bind_Contap_SurfFunction(py::module &);
void bind_Contap_Contour(py::module &);
void bind_Contap_HContTool(py::module &);
void bind_Contap_HCurve2dTool(py::module &);
void bind_Contap_TheIWLineOfTheIWalking(py::module &);
void bind_Contap_SequenceOfIWLineOfTheIWalking(py::module &);
void bind_Contap_SurfProps(py::module &);
void bind_Contap_TheIWalking(py::module &);

PYBIND11_MODULE(Contap, mod) {

py::module::import("OCCT.math");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.IntWalk");
py::module::import("OCCT.Bnd");

bind_Contap_TFunction(mod);
bind_Contap_IType(mod);
bind_Contap_ArcFunction(mod);
bind_Contap_ContAna(mod);
bind_Contap_Point(mod);
bind_Contap_TheSequenceOfPoint(mod);
bind_Contap_TheHSequenceOfPoint(mod);
bind_Contap_Line(mod);
bind_Contap_TheSequenceOfLine(mod);
bind_Contap_ThePathPointOfTheSearch(mod);
bind_Contap_TheSegmentOfTheSearch(mod);
bind_Contap_SequenceOfSegmentOfTheSearch(mod);
bind_Contap_SequenceOfPathPointOfTheSearch(mod);
bind_Contap_TheSearch(mod);
bind_Contap_TheSearchInside(mod);
bind_Contap_SurfFunction(mod);
bind_Contap_Contour(mod);
bind_Contap_HContTool(mod);
bind_Contap_HCurve2dTool(mod);
bind_Contap_TheIWLineOfTheIWalking(mod);
bind_Contap_SequenceOfIWLineOfTheIWalking(mod);
bind_Contap_SurfProps(mod);
bind_Contap_TheIWalking(mod);

}
