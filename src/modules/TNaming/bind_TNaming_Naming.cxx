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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_Naming.hxx>
#include <TDF_Label.hxx>
#include <TNaming_NamedShape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TNaming_Name.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <TDF_IDFilter.hxx>
#include <TDF_AttributeIndexedMap.hxx>
#include <Standard_Type.hxx>

void bind_TNaming_Naming(py::module &mod){

py::class_<TNaming_Naming, opencascade::handle<TNaming_Naming>, TDF_Attribute> cls_TNaming_Naming(mod, "TNaming_Naming", "This attribute store the topological naming of any selected shape, when this shape is not already attached to a specific label. This class is also used to solve it when the argumentsof the toipological naming are modified.");

// Constructors
cls_TNaming_Naming.def(py::init<>());

// Fields

// Methods
cls_TNaming_Naming.def_static("GetID_", (const Standard_GUID & (*)()) &TNaming_Naming::GetID, "following code from TDesignStd ==============================");
cls_TNaming_Naming.def_static("Insert_", (opencascade::handle<TNaming_Naming> (*)(const TDF_Label &)) &TNaming_Naming::Insert, "None", py::arg("under"));
cls_TNaming_Naming.def_static("Name_", [](const TDF_Label & a0, const TopoDS_Shape & a1, const TopoDS_Shape & a2) -> opencascade::handle<TNaming_NamedShape> { return TNaming_Naming::Name(a0, a1, a2); });
cls_TNaming_Naming.def_static("Name_", [](const TDF_Label & a0, const TopoDS_Shape & a1, const TopoDS_Shape & a2, const Standard_Boolean a3) -> opencascade::handle<TNaming_NamedShape> { return TNaming_Naming::Name(a0, a1, a2, a3); });
cls_TNaming_Naming.def_static("Name_", [](const TDF_Label & a0, const TopoDS_Shape & a1, const TopoDS_Shape & a2, const Standard_Boolean a3, const Standard_Boolean a4) -> opencascade::handle<TNaming_NamedShape> { return TNaming_Naming::Name(a0, a1, a2, a3, a4); });
cls_TNaming_Naming.def_static("Name_", (opencascade::handle<TNaming_NamedShape> (*)(const TDF_Label &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TNaming_Naming::Name, "Creates a Namimg attribute at label <where> to identify the shape <Selection>. Geometry is Standard_True if we are only interested by the underlying geometry (e.g. setting a constraint). <Context> is used to find neighbours of <S> when required by the naming. If KeepOrientation is True the Selection orientation is taken into account. BNproblem == True points out that Context sub-shapes in DF have orientation differences with Context shape itself. instance method ===============", py::arg("where"), py::arg("Selection"), py::arg("Context"), py::arg("Geometry"), py::arg("KeepOrientation"), py::arg("BNproblem"));
cls_TNaming_Naming.def("IsDefined", (Standard_Boolean (TNaming_Naming::*)() const) &TNaming_Naming::IsDefined, "None");
cls_TNaming_Naming.def("GetName", (const TNaming_Name & (TNaming_Naming::*)() const) &TNaming_Naming::GetName, "None");
cls_TNaming_Naming.def("ChangeName", (TNaming_Name & (TNaming_Naming::*)()) &TNaming_Naming::ChangeName, "None");
cls_TNaming_Naming.def("Regenerate", (Standard_Boolean (TNaming_Naming::*)(TDF_LabelMap &)) &TNaming_Naming::Regenerate, "regenerate only the Name associated to me", py::arg("scope"));
cls_TNaming_Naming.def("Solve", (Standard_Boolean (TNaming_Naming::*)(TDF_LabelMap &)) &TNaming_Naming::Solve, "Regenerate recursively the whole name with scope. If scope is empty it means that all the labels of the framework are valid.", py::arg("scope"));
cls_TNaming_Naming.def("ID", (const Standard_GUID & (TNaming_Naming::*)() const) &TNaming_Naming::ID, "Deferred methods from TDF_Attribute ===================================");
cls_TNaming_Naming.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TNaming_Naming::*)() const) &TNaming_Naming::NewEmpty, "None");
cls_TNaming_Naming.def("Restore", (void (TNaming_Naming::*)(const opencascade::handle<TDF_Attribute> &)) &TNaming_Naming::Restore, "None", py::arg("With"));
cls_TNaming_Naming.def("Paste", (void (TNaming_Naming::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TNaming_Naming::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TNaming_Naming.def("References", (void (TNaming_Naming::*)(const opencascade::handle<TDF_DataSet> &) const) &TNaming_Naming::References, "None", py::arg("aDataSet"));
cls_TNaming_Naming.def("Dump", (Standard_OStream & (TNaming_Naming::*)(Standard_OStream &) const) &TNaming_Naming::Dump, "None", py::arg("anOS"));
cls_TNaming_Naming.def("ExtendedDump", (void (TNaming_Naming::*)(Standard_OStream &, const TDF_IDFilter &, TDF_AttributeIndexedMap &) const) &TNaming_Naming::ExtendedDump, "None", py::arg("anOS"), py::arg("aFilter"), py::arg("aMap"));
cls_TNaming_Naming.def_static("get_type_name_", (const char * (*)()) &TNaming_Naming::get_type_name, "None");
cls_TNaming_Naming.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_Naming::get_type_descriptor, "None");
cls_TNaming_Naming.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_Naming::*)() const) &TNaming_Naming::DynamicType, "None");

// Enums

}