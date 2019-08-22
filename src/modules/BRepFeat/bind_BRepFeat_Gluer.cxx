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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <LocOpe_Operation.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <LocOpe_Gluer.hxx>
#include <BRepFeat_Gluer.hxx>

void bind_BRepFeat_Gluer(py::module &mod){

py::class_<BRepFeat_Gluer, BRepBuilderAPI_MakeShape> cls_BRepFeat_Gluer(mod, "BRepFeat_Gluer", "One of the most significant aspects of BRepFeat functionality is the use of local operations as opposed to global ones. In a global operation, you would first construct a form of the type you wanted in your final feature, and then remove matter so that it could fit into your initial basis object. In a local operation, however, you specify the domain of the feature construction with aspects of the shape on which the feature is being created. These semantics are expressed in terms of a member shape of the basis shape from which - or up to which - matter will be added or removed. As a result, local operations make calculations simpler and faster than global operations. Glueing uses wires or edges of a face in the basis shape. These are to become a part of the feature. They are first cut out and then projected to a plane outside or inside the basis shape. By rebuilding the initial shape incorporating the edges and the faces of the tool, protrusion features can be constructed.");

// Constructors
cls_BRepFeat_Gluer.def(py::init<>());
cls_BRepFeat_Gluer.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Snew"), py::arg("Sbase"));

// Fields

// Methods
// cls_BRepFeat_Gluer.def_static("operator new_", (void * (*)(size_t)) &BRepFeat_Gluer::operator new, "None", py::arg("theSize"));
// cls_BRepFeat_Gluer.def_static("operator delete_", (void (*)(void *)) &BRepFeat_Gluer::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat_Gluer.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat_Gluer::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat_Gluer.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat_Gluer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat_Gluer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat_Gluer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat_Gluer.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat_Gluer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat_Gluer.def("Init", (void (BRepFeat_Gluer::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_Gluer::Init, "Initializes the new shape Snew and the basis shape Sbase for the local glueing operation.", py::arg("Snew"), py::arg("Sbase"));
cls_BRepFeat_Gluer.def("Bind", (void (BRepFeat_Gluer::*)(const TopoDS_Face &, const TopoDS_Face &)) &BRepFeat_Gluer::Bind, "Defines a contact between Fnew on the new shape Snew and Fbase on the basis shape Sbase. Informs other methods that Fnew in the new shape Snew is connected to the face Fbase in the basis shape Sbase. The contact faces of the glued shape must not have parts outside the contact faces of the basis shape. This indicates that glueing is possible.", py::arg("Fnew"), py::arg("Fbase"));
cls_BRepFeat_Gluer.def("Bind", (void (BRepFeat_Gluer::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepFeat_Gluer::Bind, "nforms other methods that the edge Enew in the new shape is the same as the edge Ebase in the basis shape and is therefore attached to the basis shape. This indicates that glueing is possible.", py::arg("Enew"), py::arg("Ebase"));
cls_BRepFeat_Gluer.def("OpeType", (LocOpe_Operation (BRepFeat_Gluer::*)() const) &BRepFeat_Gluer::OpeType, "Determine which operation type to use glueing or sliding.");
cls_BRepFeat_Gluer.def("BasisShape", (const TopoDS_Shape & (BRepFeat_Gluer::*)() const) &BRepFeat_Gluer::BasisShape, "Returns the basis shape of the compound shape.");
cls_BRepFeat_Gluer.def("GluedShape", (const TopoDS_Shape & (BRepFeat_Gluer::*)() const) &BRepFeat_Gluer::GluedShape, "Returns the resulting compound shape.");
cls_BRepFeat_Gluer.def("Build", (void (BRepFeat_Gluer::*)()) &BRepFeat_Gluer::Build, "This is called by Shape(). It does nothing but may be redefined.");
cls_BRepFeat_Gluer.def("IsDeleted", (Standard_Boolean (BRepFeat_Gluer::*)(const TopoDS_Shape &)) &BRepFeat_Gluer::IsDeleted, "returns the status of the Face after the shape creation.", py::arg("F"));
cls_BRepFeat_Gluer.def("Modified", (const TopTools_ListOfShape & (BRepFeat_Gluer::*)(const TopoDS_Shape &)) &BRepFeat_Gluer::Modified, "returns the list of generated Faces.", py::arg("F"));

// Enums

}