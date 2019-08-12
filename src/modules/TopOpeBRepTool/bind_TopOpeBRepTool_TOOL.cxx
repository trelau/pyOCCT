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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <gp_Pnt2d.hxx>
#include <TopOpeBRepTool_C2DF.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt.hxx>
#include <TopAbs_State.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopOpeBRepTool_TOOL.hxx>

void bind_TopOpeBRepTool_TOOL(py::module &mod){

py::class_<TopOpeBRepTool_TOOL, std::unique_ptr<TopOpeBRepTool_TOOL, Deleter<TopOpeBRepTool_TOOL>>> cls_TopOpeBRepTool_TOOL(mod, "TopOpeBRepTool_TOOL", "None");

// Constructors

// Fields

// Methods
// cls_TopOpeBRepTool_TOOL.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_TOOL::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_TOOL.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_TOOL::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_TOOL.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_TOOL::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_TOOL.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_TOOL::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_TOOL.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_TOOL::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_TOOL.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_TOOL::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_TOOL.def_static("OriinSor_", [](const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> Standard_Integer { return TopOpeBRepTool_TOOL::OriinSor(a0, a1); });
cls_TopOpeBRepTool_TOOL.def_static("OriinSor_", (Standard_Integer (*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepTool_TOOL::OriinSor, "None", py::arg("sub"), py::arg("S"), py::arg("checkclo"));
cls_TopOpeBRepTool_TOOL.def_static("OriinSorclosed_", (Standard_Integer (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_TOOL::OriinSorclosed, "None", py::arg("sub"), py::arg("S"));
cls_TopOpeBRepTool_TOOL.def_static("ClosedE_", (Standard_Boolean (*)(const TopoDS_Edge &, TopoDS_Vertex &)) &TopOpeBRepTool_TOOL::ClosedE, "None", py::arg("E"), py::arg("vclo"));
cls_TopOpeBRepTool_TOOL.def_static("ClosedS_", (Standard_Boolean (*)(const TopoDS_Face &)) &TopOpeBRepTool_TOOL::ClosedS, "None", py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("IsClosingE_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::IsClosingE, "None", py::arg("E"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("IsClosingE_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Shape &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::IsClosingE, "None", py::arg("E"), py::arg("W"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("Vertices_", (void (*)(const TopoDS_Edge &, TopTools_Array1OfShape &)) &TopOpeBRepTool_TOOL::Vertices, "None", py::arg("E"), py::arg("Vces"));
cls_TopOpeBRepTool_TOOL.def_static("Vertex_", (TopoDS_Vertex (*)(const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::Vertex, "None", py::arg("Iv"), py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("ParE_", (Standard_Real (*)(const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::ParE, "None", py::arg("Iv"), py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("OnBoundary_", (Standard_Integer (*)(const Standard_Real, const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::OnBoundary, "None", py::arg("par"), py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("UVF_", (gp_Pnt2d (*)(const Standard_Real, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_TOOL::UVF, "None", py::arg("par"), py::arg("C2DF"));
cls_TopOpeBRepTool_TOOL.def_static("ParISO_", [](const gp_Pnt2d & p2d, const TopoDS_Edge & e, const TopoDS_Face & f, Standard_Real & pare){ Standard_Boolean rv = TopOpeBRepTool_TOOL::ParISO(p2d, e, f, pare); return std::tuple<Standard_Boolean, Standard_Real &>(rv, pare); }, "None", py::arg("p2d"), py::arg("e"), py::arg("f"), py::arg("pare"));
cls_TopOpeBRepTool_TOOL.def_static("ParE2d_", [](const gp_Pnt2d & p2d, const TopoDS_Edge & e, const TopoDS_Face & f, Standard_Real & par, Standard_Real & dist){ Standard_Boolean rv = TopOpeBRepTool_TOOL::ParE2d(p2d, e, f, par, dist); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, par, dist); }, "None", py::arg("p2d"), py::arg("e"), py::arg("f"), py::arg("par"), py::arg("dist"));
cls_TopOpeBRepTool_TOOL.def_static("Getduv_", (Standard_Boolean (*)(const TopoDS_Face &, const gp_Pnt2d &, const gp_Vec &, const Standard_Real, gp_Dir2d &)) &TopOpeBRepTool_TOOL::Getduv, "None", py::arg("f"), py::arg("uv"), py::arg("dir"), py::arg("factor"), py::arg("duv"));
cls_TopOpeBRepTool_TOOL.def_static("uvApp_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Edge &, const Standard_Real, const Standard_Real, gp_Pnt2d &)) &TopOpeBRepTool_TOOL::uvApp, "None", py::arg("f"), py::arg("e"), py::arg("par"), py::arg("eps"), py::arg("uvapp"));
cls_TopOpeBRepTool_TOOL.def_static("TolUV_", (Standard_Real (*)(const TopoDS_Face &, const Standard_Real)) &TopOpeBRepTool_TOOL::TolUV, "None", py::arg("F"), py::arg("tol3d"));
cls_TopOpeBRepTool_TOOL.def_static("TolP_", (Standard_Real (*)(const TopoDS_Edge &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::TolP, "None", py::arg("E"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("minDUV_", (Standard_Real (*)(const TopoDS_Face &)) &TopOpeBRepTool_TOOL::minDUV, "None", py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("outUVbounds_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::outUVbounds, "None", py::arg("uv"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("stuvF_", [](const gp_Pnt2d & uv, const TopoDS_Face & F, Standard_Integer & onU, Standard_Integer & onV){ TopOpeBRepTool_TOOL::stuvF(uv, F, onU, onV); return std::tuple<Standard_Integer &, Standard_Integer &>(onU, onV); }, "None", py::arg("uv"), py::arg("F"), py::arg("onU"), py::arg("onV"));
cls_TopOpeBRepTool_TOOL.def_static("TggeomE_", (Standard_Boolean (*)(const Standard_Real, const BRepAdaptor_Curve &, gp_Vec &)) &TopOpeBRepTool_TOOL::TggeomE, "None", py::arg("par"), py::arg("BC"), py::arg("Tg"));
cls_TopOpeBRepTool_TOOL.def_static("TggeomE_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepTool_TOOL::TggeomE, "None", py::arg("par"), py::arg("E"), py::arg("Tg"));
cls_TopOpeBRepTool_TOOL.def_static("TgINSIDE_", [](const TopoDS_Vertex & v, const TopoDS_Edge & E, gp_Vec & Tg, Standard_Integer & OvinE){ Standard_Boolean rv = TopOpeBRepTool_TOOL::TgINSIDE(v, E, Tg, OvinE); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, OvinE); }, "None", py::arg("v"), py::arg("E"), py::arg("Tg"), py::arg("OvinE"));
cls_TopOpeBRepTool_TOOL.def_static("Tg2d_", (gp_Vec2d (*)(const Standard_Integer, const TopoDS_Edge &, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_TOOL::Tg2d, "None", py::arg("iv"), py::arg("E"), py::arg("C2DF"));
cls_TopOpeBRepTool_TOOL.def_static("Tg2dApp_", (gp_Vec2d (*)(const Standard_Integer, const TopoDS_Edge &, const TopOpeBRepTool_C2DF &, const Standard_Real)) &TopOpeBRepTool_TOOL::Tg2dApp, "None", py::arg("iv"), py::arg("E"), py::arg("C2DF"), py::arg("factor"));
cls_TopOpeBRepTool_TOOL.def_static("tryTg2dApp_", (gp_Vec2d (*)(const Standard_Integer, const TopoDS_Edge &, const TopOpeBRepTool_C2DF &, const Standard_Real)) &TopOpeBRepTool_TOOL::tryTg2dApp, "None", py::arg("iv"), py::arg("E"), py::arg("C2DF"), py::arg("factor"));
cls_TopOpeBRepTool_TOOL.def_static("XX_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, const Standard_Real, const TopoDS_Edge &, gp_Dir &)) &TopOpeBRepTool_TOOL::XX, "None", py::arg("uv"), py::arg("f"), py::arg("par"), py::arg("e"), py::arg("xx"));
cls_TopOpeBRepTool_TOOL.def_static("Nt_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, gp_Dir &)) &TopOpeBRepTool_TOOL::Nt, "None", py::arg("uv"), py::arg("f"), py::arg("normt"));
cls_TopOpeBRepTool_TOOL.def_static("NggeomF_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, gp_Vec &)) &TopOpeBRepTool_TOOL::NggeomF, "None", py::arg("uv"), py::arg("F"), py::arg("ng"));
cls_TopOpeBRepTool_TOOL.def_static("NgApp_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Dir &)) &TopOpeBRepTool_TOOL::NgApp, "None", py::arg("par"), py::arg("E"), py::arg("F"), py::arg("tola"), py::arg("ngApp"));
cls_TopOpeBRepTool_TOOL.def_static("tryNgApp_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Dir &)) &TopOpeBRepTool_TOOL::tryNgApp, "None", py::arg("par"), py::arg("E"), py::arg("F"), py::arg("tola"), py::arg("ng"));
cls_TopOpeBRepTool_TOOL.def_static("tryOriEinF_", (Standard_Integer (*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::tryOriEinF, "None", py::arg("par"), py::arg("E"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("IsQuad_", (Standard_Boolean (*)(const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::IsQuad, "None", py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("IsQuad_", (Standard_Boolean (*)(const TopoDS_Face &)) &TopOpeBRepTool_TOOL::IsQuad, "None", py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("CurvE_", [](const TopoDS_Edge & E, const Standard_Real par, const gp_Dir & tg0, Standard_Real & Curv){ Standard_Boolean rv = TopOpeBRepTool_TOOL::CurvE(E, par, tg0, Curv); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Curv); }, "None", py::arg("E"), py::arg("par"), py::arg("tg0"), py::arg("Curv"));
cls_TopOpeBRepTool_TOOL.def_static("CurvF_", [](const TopoDS_Face & F, const gp_Pnt2d & uv, const gp_Dir & tg0, Standard_Real & Curv, Standard_Boolean & direct){ Standard_Boolean rv = TopOpeBRepTool_TOOL::CurvF(F, uv, tg0, Curv, direct); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &>(rv, Curv, direct); }, "None", py::arg("F"), py::arg("uv"), py::arg("tg0"), py::arg("Curv"), py::arg("direct"));
cls_TopOpeBRepTool_TOOL.def_static("UVISO_", [](const opencascade::handle<Geom2d_Curve> & PC, Standard_Boolean & isou, Standard_Boolean & isov, gp_Dir2d & d2d, gp_Pnt2d & o2d){ Standard_Boolean rv = TopOpeBRepTool_TOOL::UVISO(PC, isou, isov, d2d, o2d); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, isou, isov); }, "None", py::arg("PC"), py::arg("isou"), py::arg("isov"), py::arg("d2d"), py::arg("o2d"));
cls_TopOpeBRepTool_TOOL.def_static("UVISO_", [](const TopOpeBRepTool_C2DF & C2DF, Standard_Boolean & isou, Standard_Boolean & isov, gp_Dir2d & d2d, gp_Pnt2d & o2d){ Standard_Boolean rv = TopOpeBRepTool_TOOL::UVISO(C2DF, isou, isov, d2d, o2d); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, isou, isov); }, "None", py::arg("C2DF"), py::arg("isou"), py::arg("isov"), py::arg("d2d"), py::arg("o2d"));
cls_TopOpeBRepTool_TOOL.def_static("UVISO_", [](const TopoDS_Edge & E, const TopoDS_Face & F, Standard_Boolean & isou, Standard_Boolean & isov, gp_Dir2d & d2d, gp_Pnt2d & o2d){ Standard_Boolean rv = TopOpeBRepTool_TOOL::UVISO(E, F, isou, isov, d2d, o2d); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, isou, isov); }, "None", py::arg("E"), py::arg("F"), py::arg("isou"), py::arg("isov"), py::arg("d2d"), py::arg("o2d"));
cls_TopOpeBRepTool_TOOL.def_static("IsonCLO_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_TOOL::IsonCLO, "None", py::arg("PC"), py::arg("onU"), py::arg("xfirst"), py::arg("xperiod"), py::arg("xtol"));
cls_TopOpeBRepTool_TOOL.def_static("IsonCLO_", (Standard_Boolean (*)(const TopOpeBRepTool_C2DF &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_TOOL::IsonCLO, "None", py::arg("C2DF"), py::arg("onU"), py::arg("xfirst"), py::arg("xperiod"), py::arg("xtol"));
cls_TopOpeBRepTool_TOOL.def_static("TrslUV_", (void (*)(const gp_Vec2d &, TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_TOOL::TrslUV, "None", py::arg("t2d"), py::arg("C2DF"));
cls_TopOpeBRepTool_TOOL.def_static("TrslUVModifE_", (Standard_Boolean (*)(const gp_Vec2d &, const TopoDS_Face &, TopoDS_Edge &)) &TopOpeBRepTool_TOOL::TrslUVModifE, "None", py::arg("t2d"), py::arg("F"), py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("Matter_", (Standard_Real (*)(const gp_Vec &, const gp_Vec &, const gp_Vec &)) &TopOpeBRepTool_TOOL::Matter, "None", py::arg("d1"), py::arg("d2"), py::arg("ref"));
cls_TopOpeBRepTool_TOOL.def_static("Matter_", (Standard_Real (*)(const gp_Vec2d &, const gp_Vec2d &)) &TopOpeBRepTool_TOOL::Matter, "None", py::arg("d1"), py::arg("d2"));
cls_TopOpeBRepTool_TOOL.def_static("Matter_", [](const gp_Dir & xx1, const gp_Dir & nt1, const gp_Dir & xx2, const gp_Dir & nt2, const Standard_Real tola, Standard_Real & Ang){ Standard_Boolean rv = TopOpeBRepTool_TOOL::Matter(xx1, nt1, xx2, nt2, tola, Ang); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Ang); }, "None", py::arg("xx1"), py::arg("nt1"), py::arg("xx2"), py::arg("nt2"), py::arg("tola"), py::arg("Ang"));
cls_TopOpeBRepTool_TOOL.def_static("Matter_", [](const TopoDS_Face & f1, const TopoDS_Face & f2, const TopoDS_Edge & e, const Standard_Real pare, const Standard_Real tola, Standard_Real & Ang){ Standard_Boolean rv = TopOpeBRepTool_TOOL::Matter(f1, f2, e, pare, tola, Ang); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Ang); }, "None", py::arg("f1"), py::arg("f2"), py::arg("e"), py::arg("pare"), py::arg("tola"), py::arg("Ang"));
cls_TopOpeBRepTool_TOOL.def_static("MatterKPtg_", [](const TopoDS_Face & f1, const TopoDS_Face & f2, const TopoDS_Edge & e, Standard_Real & Ang){ Standard_Boolean rv = TopOpeBRepTool_TOOL::MatterKPtg(f1, f2, e, Ang); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Ang); }, "None", py::arg("f1"), py::arg("f2"), py::arg("e"), py::arg("Ang"));
cls_TopOpeBRepTool_TOOL.def_static("Getstp3dF_", (Standard_Boolean (*)(const gp_Pnt &, const TopoDS_Face &, gp_Pnt2d &, TopAbs_State &)) &TopOpeBRepTool_TOOL::Getstp3dF, "None", py::arg("p"), py::arg("f"), py::arg("uv"), py::arg("st"));
cls_TopOpeBRepTool_TOOL.def_static("SplitE_", (Standard_Boolean (*)(const TopoDS_Edge &, TopTools_ListOfShape &)) &TopOpeBRepTool_TOOL::SplitE, "None", py::arg("Eanc"), py::arg("Splits"));
cls_TopOpeBRepTool_TOOL.def_static("MkShell_", (void (*)(const TopTools_ListOfShape &, TopoDS_Shape &)) &TopOpeBRepTool_TOOL::MkShell, "None", py::arg("lF"), py::arg("She"));
cls_TopOpeBRepTool_TOOL.def_static("Remove_", (Standard_Boolean (*)(TopTools_ListOfShape &, const TopoDS_Shape &)) &TopOpeBRepTool_TOOL::Remove, "None", py::arg("loS"), py::arg("toremove"));
cls_TopOpeBRepTool_TOOL.def_static("WireToFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_DataMapOfShapeListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepTool_TOOL::WireToFace, "None", py::arg("Fref"), py::arg("mapWlow"), py::arg("lFs"));
cls_TopOpeBRepTool_TOOL.def_static("EdgeONFace_", [](const Standard_Real par, const TopoDS_Edge & ed, const gp_Pnt2d & uv, const TopoDS_Face & fa, Standard_Boolean & isonfa){ Standard_Boolean rv = TopOpeBRepTool_TOOL::EdgeONFace(par, ed, uv, fa, isonfa); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, isonfa); }, "None", py::arg("par"), py::arg("ed"), py::arg("uv"), py::arg("fa"), py::arg("isonfa"));

// Enums

}