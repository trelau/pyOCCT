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
#include <TopoDS_Face.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_DataMapOfOrientedShapeInteger.hxx>
#include <TopOpeBRepTool_C2DF.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopOpeBRepTool_DataMapOfOrientedShapeC2DF.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopOpeBRepTool_CORRISO.hxx>

void bind_TopOpeBRepTool_CORRISO(py::module &mod){

py::class_<TopOpeBRepTool_CORRISO, std::unique_ptr<TopOpeBRepTool_CORRISO>> cls_TopOpeBRepTool_CORRISO(mod, "TopOpeBRepTool_CORRISO", "Fref is built on x-periodic surface (x=u,v). S built on Fref's geometry, should be UVClosed.");

// Constructors
cls_TopOpeBRepTool_CORRISO.def(py::init<>());
cls_TopOpeBRepTool_CORRISO.def(py::init<const TopoDS_Face &>(), py::arg("FRef"));

// Fields

// Methods
// cls_TopOpeBRepTool_CORRISO.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_CORRISO::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_CORRISO::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_CORRISO::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_CORRISO::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_CORRISO::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_CORRISO::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_CORRISO.def("Fref", (const TopoDS_Face & (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::Fref, "None");
cls_TopOpeBRepTool_CORRISO.def("GASref", (const GeomAdaptor_Surface & (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::GASref, "None");
cls_TopOpeBRepTool_CORRISO.def("Refclosed", [](TopOpeBRepTool_CORRISO &self, const Standard_Integer x, Standard_Real & xperiod){ Standard_Boolean rv = self.Refclosed(x, xperiod); return std::tuple<Standard_Boolean, Standard_Real &>(rv, xperiod); }, "None", py::arg("x"), py::arg("xperiod"));
cls_TopOpeBRepTool_CORRISO.def("Init", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Shape &)) &TopOpeBRepTool_CORRISO::Init, "None", py::arg("S"));
cls_TopOpeBRepTool_CORRISO.def("S", (const TopoDS_Shape & (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::S, "None");
cls_TopOpeBRepTool_CORRISO.def("Eds", (const TopTools_ListOfShape & (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::Eds, "None");
cls_TopOpeBRepTool_CORRISO.def("UVClosed", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::UVClosed, "None");
cls_TopOpeBRepTool_CORRISO.def("Tol", (Standard_Real (TopOpeBRepTool_CORRISO::*)(const Standard_Integer, const Standard_Real) const) &TopOpeBRepTool_CORRISO::Tol, "None", py::arg("I"), py::arg("tol3d"));
cls_TopOpeBRepTool_CORRISO.def("PurgeFyClosingE", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepTool_CORRISO::PurgeFyClosingE, "None", py::arg("ClEds"), py::arg("fyClEds"));
cls_TopOpeBRepTool_CORRISO.def("EdgeOUTofBoundsUV", [](TopOpeBRepTool_CORRISO &self, const TopoDS_Edge & E, const Standard_Boolean onU, const Standard_Real tolx, Standard_Real & parspE){ Standard_Integer rv = self.EdgeOUTofBoundsUV(E, onU, tolx, parspE); return std::tuple<Standard_Integer, Standard_Real &>(rv, parspE); }, "None", py::arg("E"), py::arg("onU"), py::arg("tolx"), py::arg("parspE"));
cls_TopOpeBRepTool_CORRISO.def("EdgesOUTofBoundsUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, const Standard_Boolean, const Standard_Real, TopTools_DataMapOfOrientedShapeInteger &) const) &TopOpeBRepTool_CORRISO::EdgesOUTofBoundsUV, "None", py::arg("EdsToCheck"), py::arg("onU"), py::arg("tolx"), py::arg("FyEds"));
cls_TopOpeBRepTool_CORRISO.def("EdgeWithFaultyUV", [](TopOpeBRepTool_CORRISO &self, const TopoDS_Edge & E, Standard_Integer & Ivfaulty){ Standard_Boolean rv = self.EdgeWithFaultyUV(E, Ivfaulty); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, Ivfaulty); }, "None", py::arg("E"), py::arg("Ivfaulty"));
cls_TopOpeBRepTool_CORRISO.def("EdgesWithFaultyUV", [](TopOpeBRepTool_CORRISO &self, const TopTools_ListOfShape & a0, const Standard_Integer a1, TopTools_DataMapOfOrientedShapeInteger & a2) -> Standard_Boolean { return self.EdgesWithFaultyUV(a0, a1, a2); });
cls_TopOpeBRepTool_CORRISO.def("EdgesWithFaultyUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, const Standard_Integer, TopTools_DataMapOfOrientedShapeInteger &, const Standard_Boolean) const) &TopOpeBRepTool_CORRISO::EdgesWithFaultyUV, "None", py::arg("EdsToCheck"), py::arg("nfybounds"), py::arg("FyEds"), py::arg("stopatfirst"));
cls_TopOpeBRepTool_CORRISO.def("EdgeWithFaultyUV", [](TopOpeBRepTool_CORRISO &self, const TopTools_ListOfShape & EdsToCheck, const Standard_Integer nfybounds, TopoDS_Shape & fyE, Standard_Integer & Ifaulty){ Standard_Boolean rv = self.EdgeWithFaultyUV(EdsToCheck, nfybounds, fyE, Ifaulty); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, Ifaulty); }, "None", py::arg("EdsToCheck"), py::arg("nfybounds"), py::arg("fyE"), py::arg("Ifaulty"));
cls_TopOpeBRepTool_CORRISO.def("TrslUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const Standard_Boolean, const TopTools_DataMapOfOrientedShapeInteger &)) &TopOpeBRepTool_CORRISO::TrslUV, "None", py::arg("onU"), py::arg("FyEds"));
cls_TopOpeBRepTool_CORRISO.def("GetnewS", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(TopoDS_Face &) const) &TopOpeBRepTool_CORRISO::GetnewS, "None", py::arg("newS"));
cls_TopOpeBRepTool_CORRISO.def("UVRep", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Edge &, TopOpeBRepTool_C2DF &) const) &TopOpeBRepTool_CORRISO::UVRep, "None", py::arg("E"), py::arg("C2DF"));
cls_TopOpeBRepTool_CORRISO.def("SetUVRep", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Edge &, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_CORRISO::SetUVRep, "None", py::arg("E"), py::arg("C2DF"));
cls_TopOpeBRepTool_CORRISO.def("Connexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, TopTools_ListOfShape &) const) &TopOpeBRepTool_CORRISO::Connexity, "None", py::arg("V"), py::arg("Eds"));
cls_TopOpeBRepTool_CORRISO.def("SetConnexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, const TopTools_ListOfShape &)) &TopOpeBRepTool_CORRISO::SetConnexity, "None", py::arg("V"), py::arg("Eds"));
cls_TopOpeBRepTool_CORRISO.def("AddNewConnexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, const TopoDS_Edge &)) &TopOpeBRepTool_CORRISO::AddNewConnexity, "None", py::arg("V"), py::arg("E"));
cls_TopOpeBRepTool_CORRISO.def("RemoveOldConnexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, const TopoDS_Edge &)) &TopOpeBRepTool_CORRISO::RemoveOldConnexity, "None", py::arg("V"), py::arg("E"));

// Enums

}