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
#include <Standard.hxx>
#include <GeomAbs_CurveType.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dInt_Geom2dCurveTool.hxx>

void bind_Geom2dInt_Geom2dCurveTool(py::module &mod){

py::class_<Geom2dInt_Geom2dCurveTool> cls_Geom2dInt_Geom2dCurveTool(mod, "Geom2dInt_Geom2dCurveTool", "This class provides a Geom2dCurveTool as < Geom2dCurveTool from IntCurve > from a Tool as < Geom2dCurveTool from Adaptor3d > .");

// Constructors

// Fields

// Methods
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_Geom2dCurveTool::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_Geom2dCurveTool::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_Geom2dCurveTool::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_Geom2dCurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_Geom2dCurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_Geom2dCurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_Geom2dCurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::GetType, "None", py::arg("C"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("IsComposite_", (Standard_Boolean (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::IsComposite, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Line_", (gp_Lin2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Line, "Returns the Lin2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Line.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Circle_", (gp_Circ2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Circle, "Returns the Circ2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Circle.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Ellipse_", (gp_Elips2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Ellipse, "Returns the Elips2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Ellipse.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Parabola_", (gp_Parab2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Parabola, "Returns the Parab2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Parabola.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Hyperbola, "Returns the Hypr2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Hyperbola.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("EpsX_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::EpsX, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("EpsX_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &Geom2dInt_Geom2dCurveTool::EpsX, "None", py::arg("C"), py::arg("Eps_XYZ"));
cls_Geom2dInt_Geom2dCurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::NbSamples, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Geom2dInt_Geom2dCurveTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));
cls_Geom2dInt_Geom2dCurveTool.def_static("FirstParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::FirstParameter, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("LastParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::LastParameter, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Value_", (gp_Pnt2d (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &Geom2dInt_Geom2dCurveTool::Value, "None", py::arg("C"), py::arg("X"));
cls_Geom2dInt_Geom2dCurveTool.def_static("D0_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &)) &Geom2dInt_Geom2dCurveTool::D0, "None", py::arg("C"), py::arg("U"), py::arg("P"));
cls_Geom2dInt_Geom2dCurveTool.def_static("D1_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &Geom2dInt_Geom2dCurveTool::D1, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"));
cls_Geom2dInt_Geom2dCurveTool.def_static("D2_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dInt_Geom2dCurveTool::D2, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"));
cls_Geom2dInt_Geom2dCurveTool.def_static("D3_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dInt_Geom2dCurveTool::D3, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("V"));
cls_Geom2dInt_Geom2dCurveTool.def_static("DN_", (gp_Vec2d (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Integer)) &Geom2dInt_Geom2dCurveTool::DN, "None", py::arg("C"), py::arg("U"), py::arg("N"));
cls_Geom2dInt_Geom2dCurveTool.def_static("NbIntervals_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::NbIntervals, "output the number of interval of continuity C2 of the curve", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Intervals_", (void (*)(const Adaptor2d_Curve2d &, TColStd_Array1OfReal &)) &Geom2dInt_Geom2dCurveTool::Intervals, "compute Tab.", py::arg("C"), py::arg("Tab"));
cls_Geom2dInt_Geom2dCurveTool.def_static("GetInterval_", [](const Adaptor2d_Curve2d & C, const Standard_Integer Index, const TColStd_Array1OfReal & Tab, Standard_Real & U1, Standard_Real & U2){ Geom2dInt_Geom2dCurveTool::GetInterval(C, Index, Tab, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "output the bounds of interval of index <Index> used if Type == Composite.", py::arg("C"), py::arg("Index"), py::arg("Tab"), py::arg("U1"), py::arg("U2"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Degree_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Degree, "None", py::arg("C"));

// Enums

}