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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepDS_CheckStatus.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopOpeBRepDS_Check.hxx>
#include <Standard_Type.hxx>
#include <TopOpeBRepDS_DataMapOfCheckStatus.hxx>

void bind_TopOpeBRepDS_Check(py::module &mod){

py::class_<TopOpeBRepDS_Check, opencascade::handle<TopOpeBRepDS_Check>, Standard_Transient> cls_TopOpeBRepDS_Check(mod, "TopOpeBRepDS_Check", "a tool verifing integrity and structure of DS");

// Constructors
cls_TopOpeBRepDS_Check.def(py::init<>());
cls_TopOpeBRepDS_Check.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Fields

// Methods
cls_TopOpeBRepDS_Check.def("ChkIntg", (Standard_Boolean (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::ChkIntg, "Check integrition of DS");
cls_TopOpeBRepDS_Check.def("ChkIntgInterf", (Standard_Boolean (TopOpeBRepDS_Check::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_Check::ChkIntgInterf, "Check integrition of interferences (les supports et les geometries de LI)", py::arg("LI"));
cls_TopOpeBRepDS_Check.def("CheckDS", (Standard_Boolean (TopOpeBRepDS_Check::*)(const Standard_Integer, const TopOpeBRepDS_Kind)) &TopOpeBRepDS_Check::CheckDS, "Verifie que le ieme element de la DS existe, et pour un K de type topologique, verifie qu'il est du bon type (VERTEX, EDGE, WIRE, FACE, SHELL ou SOLID)", py::arg("i"), py::arg("K"));
cls_TopOpeBRepDS_Check.def("ChkIntgSamDom", (Standard_Boolean (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::ChkIntgSamDom, "Check integrition des champs SameDomain de la DS");
cls_TopOpeBRepDS_Check.def("CheckShapes", (Standard_Boolean (TopOpeBRepDS_Check::*)(const TopTools_ListOfShape &) const) &TopOpeBRepDS_Check::CheckShapes, "Verifie que les Shapes existent bien dans la DS Utile pour les Shapes SameDomain si la liste est vide, renvoie vrai", py::arg("LS"));
cls_TopOpeBRepDS_Check.def("OneVertexOnPnt", (Standard_Boolean (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::OneVertexOnPnt, "Verifie que les Vertex non SameDomain sont bien nonSameDomain, que les vertex sameDomain sont bien SameDomain, que les Points sont non confondus ni entre eux, ni avec des Vertex.");
cls_TopOpeBRepDS_Check.def("HDS", (const opencascade::handle<TopOpeBRepDS_HDataStructure> & (TopOpeBRepDS_Check::*)() const) &TopOpeBRepDS_Check::HDS, "None");
cls_TopOpeBRepDS_Check.def("ChangeHDS", (opencascade::handle<TopOpeBRepDS_HDataStructure> & (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::ChangeHDS, "None");
cls_TopOpeBRepDS_Check.def("PrintIntg", (Standard_OStream & (TopOpeBRepDS_Check::*)(Standard_OStream &)) &TopOpeBRepDS_Check::PrintIntg, "None", py::arg("S"));
cls_TopOpeBRepDS_Check.def("Print", (Standard_OStream & (TopOpeBRepDS_Check::*)(const TopOpeBRepDS_CheckStatus, Standard_OStream &)) &TopOpeBRepDS_Check::Print, "Prints the name of CheckStatus <stat> as a String", py::arg("stat"), py::arg("S"));
cls_TopOpeBRepDS_Check.def("PrintShape", (Standard_OStream & (TopOpeBRepDS_Check::*)(const TopAbs_ShapeEnum, Standard_OStream &)) &TopOpeBRepDS_Check::PrintShape, "Prints the name of CheckStatus <stat> as a String", py::arg("SE"), py::arg("S"));
cls_TopOpeBRepDS_Check.def("PrintShape", (Standard_OStream & (TopOpeBRepDS_Check::*)(const Standard_Integer, Standard_OStream &)) &TopOpeBRepDS_Check::PrintShape, "Prints the name of CheckStatus <stat> as a String", py::arg("index"), py::arg("S"));
cls_TopOpeBRepDS_Check.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Check::get_type_name, "None");
cls_TopOpeBRepDS_Check.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Check::get_type_descriptor, "None");
cls_TopOpeBRepDS_Check.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Check::*)() const) &TopOpeBRepDS_Check::DynamicType, "None");

// Enums

}