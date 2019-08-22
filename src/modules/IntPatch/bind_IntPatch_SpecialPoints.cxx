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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <math_Vector.hxx>
#include <IntPatch_Point.hxx>
#include <IntPatch_SpecPntType.hxx>
#include <IntPatch_SpecialPoints.hxx>

void bind_IntPatch_SpecialPoints(py::module &mod){

py::class_<IntPatch_SpecialPoints> cls_IntPatch_SpecialPoints(mod, "IntPatch_SpecialPoints", "None");

// Constructors

// Fields

// Methods
cls_IntPatch_SpecialPoints.def_static("AddCrossUVIsoPoint_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const Standard_Real a3, IntSurf_PntOn2S & a4) -> Standard_Boolean { return IntPatch_SpecialPoints::AddCrossUVIsoPoint(a0, a1, a2, a3, a4); });
cls_IntPatch_SpecialPoints.def_static("AddCrossUVIsoPoint_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &, const Standard_Real, IntSurf_PntOn2S &, const Standard_Boolean)) &IntPatch_SpecialPoints::AddCrossUVIsoPoint, "Adds the point defined as intersection of two isolines (U = 0 and V = 0) on theQSurf in theLine. theRefPt is used to correct adjusting parameters. If theIsReversed is TRUE then theQSurf correspond to the second (otherwise, the first) surface while forming intersection point IntSurf_PntOn2S.", py::arg("theQSurf"), py::arg("thePSurf"), py::arg("theRefPt"), py::arg("theTol3d"), py::arg("theAddedPoint"), py::arg("theIsReversed"));
cls_IntPatch_SpecialPoints.def_static("AddPointOnUorVIso_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const Standard_Boolean a3, const math_Vector & a4, const math_Vector & a5, const math_Vector & a6, const math_Vector & a7, IntSurf_PntOn2S & a8) -> Standard_Boolean { return IntPatch_SpecialPoints::AddPointOnUorVIso(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_IntPatch_SpecialPoints.def_static("AddPointOnUorVIso_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &, const Standard_Boolean, const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, IntSurf_PntOn2S &, const Standard_Boolean)) &IntPatch_SpecialPoints::AddPointOnUorVIso, "Adds the point lain strictly in the isoline U = 0 or V = 0 of theQSurf, in theLine. theRefPt is used to correct adjusting parameters. If theIsReversed is TRUE then theQSurf corresponds to the second (otherwise, the first) surface while forming intersection point IntSurf_PntOn2S.", py::arg("theQSurf"), py::arg("thePSurf"), py::arg("theRefPt"), py::arg("theIsU"), py::arg("theToler"), py::arg("theInitPoint"), py::arg("theInfBound"), py::arg("theSupBound"), py::arg("theAddedPoint"), py::arg("theIsReversed"));
cls_IntPatch_SpecialPoints.def_static("AddSingularPole_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const Standard_Real a3, IntPatch_Point & a4, IntSurf_PntOn2S & a5) -> Standard_Boolean { return IntPatch_SpecialPoints::AddSingularPole(a0, a1, a2, a3, a4, a5); });
cls_IntPatch_SpecialPoints.def_static("AddSingularPole_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const Standard_Real a3, IntPatch_Point & a4, IntSurf_PntOn2S & a5, const Standard_Boolean a6) -> Standard_Boolean { return IntPatch_SpecialPoints::AddSingularPole(a0, a1, a2, a3, a4, a5, a6); });
cls_IntPatch_SpecialPoints.def_static("AddSingularPole_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &, const Standard_Real, IntPatch_Point &, IntSurf_PntOn2S &, const Standard_Boolean, const Standard_Boolean)) &IntPatch_SpecialPoints::AddSingularPole, "Computes the pole of sphere to add it in the intersection line. Stores the result in theAddedPoint variable (does not add in the line). At that, cone and sphere (with singularity) must be set in theQSurf parameter. By default (if theIsReversed == FALSE), theQSurf is the first surface of the Walking line. If it is not, theIsReversed parameter must be set to TRUE. theIsReqRefCheck is TRUE if and only if 3D-point of theRefPt must be pole or apex for check (e.g. if it is vertex). thePtIso is the reference point for obtaining isoline where must be placed the Apex/Pole.", py::arg("theQSurf"), py::arg("thePSurf"), py::arg("thePtIso"), py::arg("theTol3d"), py::arg("theVertex"), py::arg("theAddedPoint"), py::arg("theIsReversed"), py::arg("theIsReqRefCheck"));
cls_IntPatch_SpecialPoints.def_static("ContinueAfterSpecialPoint_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const IntPatch_SpecPntType a3, const Standard_Real a4, IntSurf_PntOn2S & a5) -> Standard_Boolean { return IntPatch_SpecialPoints::ContinueAfterSpecialPoint(a0, a1, a2, a3, a4, a5); });
cls_IntPatch_SpecialPoints.def_static("ContinueAfterSpecialPoint_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &, const IntPatch_SpecPntType, const Standard_Real, IntSurf_PntOn2S &, const Standard_Boolean)) &IntPatch_SpecialPoints::ContinueAfterSpecialPoint, "Special point has already been added in the line. Now, we need in correct prolongation of the line or in start new line. This function returns new point.", py::arg("theQSurf"), py::arg("thePSurf"), py::arg("theRefPt"), py::arg("theSPType"), py::arg("theTol2D"), py::arg("theNewPoint"), py::arg("theIsReversed"));
// cls_IntPatch_SpecialPoints.def_static("AdjustPointAndVertex_", [](const IntSurf_PntOn2S & a0, const Standard_Real [4] a1, IntSurf_PntOn2S & a2) -> void { return IntPatch_SpecialPoints::AdjustPointAndVertex(a0, a1, a2); });
// cls_IntPatch_SpecialPoints.def_static("AdjustPointAndVertex_", (void (*)(const IntSurf_PntOn2S &, const Standard_Real [4], IntSurf_PntOn2S &, IntPatch_Point *const)) &IntPatch_SpecialPoints::AdjustPointAndVertex, "Sets theNewPoint parameters in 2D-space the closest to theRefPoint with help of adding/subtracting corresponding periods. theArrPeriods must be filled as follows: {<U-period of 1st surface>, <V-period of 1st surface>, <U-period of 2nd surface>, <V-period of 2nd surface>}. If theVertex != 0 then its parameters will be filled as corresponding parameters of theNewPoint.", py::arg("theRefPoint"), py::arg("theArrPeriods"), py::arg("theNewPoint"), py::arg("theVertex"));

// Enums

}