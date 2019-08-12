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

void bind_IntPatch_IType(py::module &);
void bind_IntPatch_SpecPntType(py::module &);
void bind_IntPatch_Point(py::module &);
void bind_IntPatch_SequenceOfPoint(py::module &);
void bind_IntPatch_Line(py::module &);
void bind_IntPatch_SequenceOfLine(py::module &);
void bind_IntPatch_Intersection(py::module &);
void bind_IntPatch_ALine(py::module &);
void bind_IntPatch_ALineToWLine(py::module &);
void bind_IntPatch_ArcFunction(py::module &);
void bind_IntPatch_CSFunction(py::module &);
void bind_IntPatch_CurvIntSurf(py::module &);
void bind_IntPatch_GLine(py::module &);
void bind_IntPatch_HCurve2dTool(py::module &);
void bind_IntPatch_HInterTool(py::module &);
void bind_IntPatch_ThePathPointOfTheSOnBounds(py::module &);
void bind_IntPatch_TheSegmentOfTheSOnBounds(py::module &);
void bind_IntPatch_SequenceOfSegmentOfTheSOnBounds(py::module &);
void bind_IntPatch_SequenceOfPathPointOfTheSOnBounds(py::module &);
void bind_IntPatch_TheSOnBounds(py::module &);
void bind_IntPatch_ImpImpIntersection(py::module &);
void bind_IntPatch_TheSearchInside(py::module &);
void bind_IntPatch_ImpPrmIntersection(py::module &);
void bind_IntPatch_InterferencePolyhedron(py::module &);
void bind_IntPatch_LineConstructor(py::module &);
void bind_IntPatch_PointLine(py::module &);
void bind_IntPatch_Polygo(py::module &);
void bind_IntPatch_PolyArc(py::module &);
void bind_IntPatch_Polyhedron(py::module &);
void bind_IntPatch_PolyhedronTool(py::module &);
void bind_IntPatch_PolyLine(py::module &);
void bind_IntPatch_PrmPrmIntersection(py::module &);
void bind_IntPatch_PrmPrmIntersection_T3Bits(py::module &);
void bind_IntPatch_RLine(py::module &);
void bind_IntPatch_RstInt(py::module &);
void bind_IntPatch_SearchPnt(py::module &);
void bind_IntPatch_TheIWLineOfTheIWalking(py::module &);
void bind_IntPatch_SequenceOfIWLineOfTheIWalking(py::module &);
void bind_IntPatch_SpecialPoints(py::module &);
void bind_IntPatch_TheIWalking(py::module &);
void bind_IntPatch_TheSurfFunction(py::module &);
void bind_IntPatch_WLine(py::module &);
void bind_IntPatch_WLineTool(py::module &);

PYBIND11_MODULE(IntPatch, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.IntAna");
py::module::import("OCCT.math");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Intf");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.IntWalk");

bind_IntPatch_IType(mod);
bind_IntPatch_SpecPntType(mod);
bind_IntPatch_Point(mod);
bind_IntPatch_SequenceOfPoint(mod);
bind_IntPatch_Line(mod);
bind_IntPatch_SequenceOfLine(mod);
bind_IntPatch_Intersection(mod);
bind_IntPatch_ALine(mod);
bind_IntPatch_ALineToWLine(mod);
bind_IntPatch_ArcFunction(mod);
bind_IntPatch_CSFunction(mod);
bind_IntPatch_CurvIntSurf(mod);
bind_IntPatch_GLine(mod);
bind_IntPatch_HCurve2dTool(mod);
bind_IntPatch_HInterTool(mod);
bind_IntPatch_ThePathPointOfTheSOnBounds(mod);
bind_IntPatch_TheSegmentOfTheSOnBounds(mod);
bind_IntPatch_SequenceOfSegmentOfTheSOnBounds(mod);
bind_IntPatch_SequenceOfPathPointOfTheSOnBounds(mod);
bind_IntPatch_TheSOnBounds(mod);
bind_IntPatch_ImpImpIntersection(mod);
bind_IntPatch_TheSearchInside(mod);
bind_IntPatch_ImpPrmIntersection(mod);
bind_IntPatch_InterferencePolyhedron(mod);
bind_IntPatch_LineConstructor(mod);
bind_IntPatch_PointLine(mod);
bind_IntPatch_Polygo(mod);
bind_IntPatch_PolyArc(mod);
bind_IntPatch_Polyhedron(mod);
bind_IntPatch_PolyhedronTool(mod);
bind_IntPatch_PolyLine(mod);
bind_IntPatch_PrmPrmIntersection(mod);
bind_IntPatch_PrmPrmIntersection_T3Bits(mod);
bind_IntPatch_RLine(mod);
bind_IntPatch_RstInt(mod);
bind_IntPatch_SearchPnt(mod);
bind_IntPatch_TheIWLineOfTheIWalking(mod);
bind_IntPatch_SequenceOfIWLineOfTheIWalking(mod);
bind_IntPatch_SpecialPoints(mod);
bind_IntPatch_TheIWalking(mod);
bind_IntPatch_TheSurfFunction(mod);
bind_IntPatch_WLine(mod);
bind_IntPatch_WLineTool(mod);

}
