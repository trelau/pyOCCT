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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Face.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <gp_Dir.hxx>
#include <TopOpeBRepTool_ShapeTool.hxx>

void bind_TopOpeBRepTool_ShapeTool(py::module &mod){

py::class_<TopOpeBRepTool_ShapeTool, std::unique_ptr<TopOpeBRepTool_ShapeTool, Deleter<TopOpeBRepTool_ShapeTool>>> cls_TopOpeBRepTool_ShapeTool(mod, "TopOpeBRepTool_ShapeTool", "None");

// Constructors

// Fields

// Methods
// cls_TopOpeBRepTool_ShapeTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_ShapeTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_ShapeTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_ShapeTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_ShapeTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_ShapeTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_ShapeTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_ShapeTool.def_static("Tolerance_", (Standard_Real (*)(const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::Tolerance, "Returns the tolerance of the shape <S>. If the shape <S> is Null, returns 0.", py::arg("S"));
cls_TopOpeBRepTool_ShapeTool.def_static("Pnt_", (gp_Pnt (*)(const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::Pnt, "Returns 3D point of vertex <S>.", py::arg("S"));
cls_TopOpeBRepTool_ShapeTool.def_static("BASISCURVE_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<Geom_Curve> &)) &TopOpeBRepTool_ShapeTool::BASISCURVE, "None", py::arg("C"));
cls_TopOpeBRepTool_ShapeTool.def_static("BASISCURVE_", (opencascade::handle<Geom_Curve> (*)(const TopoDS_Edge &)) &TopOpeBRepTool_ShapeTool::BASISCURVE, "None", py::arg("E"));
cls_TopOpeBRepTool_ShapeTool.def_static("BASISSURFACE_", (opencascade::handle<Geom_Surface> (*)(const opencascade::handle<Geom_Surface> &)) &TopOpeBRepTool_ShapeTool::BASISSURFACE, "None", py::arg("S"));
cls_TopOpeBRepTool_ShapeTool.def_static("BASISSURFACE_", (opencascade::handle<Geom_Surface> (*)(const TopoDS_Face &)) &TopOpeBRepTool_ShapeTool::BASISSURFACE, "None", py::arg("F"));
cls_TopOpeBRepTool_ShapeTool.def_static("UVBOUNDS_", [](const opencascade::handle<Geom_Surface> & S, Standard_Boolean & UPeri, Standard_Boolean & VPeri, Standard_Real & Umin, Standard_Real & Umax, Standard_Real & Vmin, Standard_Real & Vmax){ TopOpeBRepTool_ShapeTool::UVBOUNDS(S, UPeri, VPeri, Umin, Umax, Vmin, Vmax); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UPeri, VPeri, Umin, Umax, Vmin, Vmax); }, "None", py::arg("S"), py::arg("UPeri"), py::arg("VPeri"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
cls_TopOpeBRepTool_ShapeTool.def_static("UVBOUNDS_", [](const TopoDS_Face & F, Standard_Boolean & UPeri, Standard_Boolean & VPeri, Standard_Real & Umin, Standard_Real & Umax, Standard_Real & Vmin, Standard_Real & Vmax){ TopOpeBRepTool_ShapeTool::UVBOUNDS(F, UPeri, VPeri, Umin, Umax, Vmin, Vmax); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UPeri, VPeri, Umin, Umax, Vmin, Vmax); }, "None", py::arg("F"), py::arg("UPeri"), py::arg("VPeri"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
cls_TopOpeBRepTool_ShapeTool.def_static("AdjustOnPeriodic_", [](const TopoDS_Shape & S, Standard_Real & u, Standard_Real & v){ TopOpeBRepTool_ShapeTool::AdjustOnPeriodic(S, u, v); return std::tuple<Standard_Real &, Standard_Real &>(u, v); }, "ajust u,v values in UVBounds of the domain of the geometric shape <S>, according to Uperiodicity and VPeriodicity of the domain. <S> is assumed to be a face. u and/or v is/are not modified when the domain is not periodic in U and/or V .", py::arg("S"), py::arg("u"), py::arg("v"));
cls_TopOpeBRepTool_ShapeTool.def_static("Closed_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::Closed, "indicates wheter shape S1 is a closing shape on S2 or not.", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepTool_ShapeTool.def_static("PeriodizeParameter_", (Standard_Real (*)(const Standard_Real, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::PeriodizeParameter, "None", py::arg("par"), py::arg("EE"), py::arg("FF"));
cls_TopOpeBRepTool_ShapeTool.def_static("ShapesSameOriented_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::ShapesSameOriented, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepTool_ShapeTool.def_static("SurfacesSameOriented_", (Standard_Boolean (*)(const BRepAdaptor_Surface &, const BRepAdaptor_Surface &)) &TopOpeBRepTool_ShapeTool::SurfacesSameOriented, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepTool_ShapeTool.def_static("FacesSameOriented_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::FacesSameOriented, "None", py::arg("F1"), py::arg("F2"));
cls_TopOpeBRepTool_ShapeTool.def_static("CurvesSameOriented_", (Standard_Boolean (*)(const BRepAdaptor_Curve &, const BRepAdaptor_Curve &)) &TopOpeBRepTool_ShapeTool::CurvesSameOriented, "None", py::arg("C1"), py::arg("C2"));
cls_TopOpeBRepTool_ShapeTool.def_static("EdgesSameOriented_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::EdgesSameOriented, "None", py::arg("E1"), py::arg("E2"));
cls_TopOpeBRepTool_ShapeTool.def_static("EdgeData_", [](const BRepAdaptor_Curve & BRAC, const Standard_Real P, gp_Dir & T, gp_Dir & N, Standard_Real & C){ Standard_Real rv = TopOpeBRepTool_ShapeTool::EdgeData(BRAC, P, T, N, C); return std::tuple<Standard_Real, Standard_Real &>(rv, C); }, "Compute tangent T, normal N, curvature C at point of parameter P on curve BRAC. Returns the tolerance indicating if T,N are null.", py::arg("BRAC"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("C"));
cls_TopOpeBRepTool_ShapeTool.def_static("EdgeData_", [](const TopoDS_Shape & E, const Standard_Real P, gp_Dir & T, gp_Dir & N, Standard_Real & C){ Standard_Real rv = TopOpeBRepTool_ShapeTool::EdgeData(E, P, T, N, C); return std::tuple<Standard_Real, Standard_Real &>(rv, C); }, "Same as previous on edge E.", py::arg("E"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("C"));
cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3dU_", (Standard_Real (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3dU, "None", py::arg("SU"), py::arg("Tol2d"));
cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3dV_", (Standard_Real (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3dV, "None", py::arg("SU"), py::arg("Tol2d"));
cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3d_", (Standard_Real (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3d, "None", py::arg("SU"), py::arg("Tol2d"));
cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3d_", (Standard_Real (*)(const TopoDS_Face &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3d, "None", py::arg("F"), py::arg("Tol2d"));

// Enums

}