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
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Delta.hxx>
#include <Standard_OStream.hxx>
#include <TDF_HAllocator.hxx>
#include <TDF_Transaction.hxx>
#include <TDF_LabelNode.hxx>
#include <TDF_Data.hxx>
#include <Standard_Type.hxx>
#include <TDF_LabelNodePtr.hxx>
#include <TColStd_ListOfInteger.hxx>

void bind_TDF_Data(py::module &mod){

py::class_<TDF_Data, opencascade::handle<TDF_Data>, Standard_Transient> cls_TDF_Data(mod, "TDF_Data", "This class is used to manipulate a complete independant, self sufficient data structure and its services:");

// Constructors
cls_TDF_Data.def(py::init<>());

// Fields

// Methods
cls_TDF_Data.def("Root", (const TDF_Label (TDF_Data::*)() const) &TDF_Data::Root, "Returns the root label of the Data structure.");
cls_TDF_Data.def("Transaction", (Standard_Integer (TDF_Data::*)() const) &TDF_Data::Transaction, "Returns the current transaction number.");
cls_TDF_Data.def("Time", (Standard_Integer (TDF_Data::*)() const) &TDF_Data::Time, "Returns the current tick. It is incremented each Commit.");
cls_TDF_Data.def("IsApplicable", (Standard_Boolean (TDF_Data::*)(const opencascade::handle<TDF_Delta> &) const) &TDF_Data::IsApplicable, "Returns true if <aDelta> is applicable HERE and NOW.", py::arg("aDelta"));
cls_TDF_Data.def("Undo", [](TDF_Data &self, const opencascade::handle<TDF_Delta> & a0) -> opencascade::handle<TDF_Delta> { return self.Undo(a0); });
cls_TDF_Data.def("Undo", (opencascade::handle<TDF_Delta> (TDF_Data::*)(const opencascade::handle<TDF_Delta> &, const Standard_Boolean)) &TDF_Data::Undo, "Apply <aDelta> to undo a set of attribute modifications.", py::arg("aDelta"), py::arg("withDelta"));
cls_TDF_Data.def("Destroy", (void (TDF_Data::*)()) &TDF_Data::Destroy, "None");
cls_TDF_Data.def("NotUndoMode", (Standard_Boolean (TDF_Data::*)() const) &TDF_Data::NotUndoMode, "Returns the undo mode status.");
cls_TDF_Data.def("Dump", (Standard_OStream & (TDF_Data::*)(Standard_OStream &) const) &TDF_Data::Dump, "Dumps the Data on <aStream>.", py::arg("anOS"));
cls_TDF_Data.def("bits_left", (Standard_OStream & (TDF_Data::*)(Standard_OStream &) const) &TDF_Data::operator<<, py::is_operator(), "None", py::arg("anOS"));
cls_TDF_Data.def("AllowModification", (void (TDF_Data::*)(const Standard_Boolean)) &TDF_Data::AllowModification, "Sets modification mode.", py::arg("isAllowed"));
cls_TDF_Data.def("IsModificationAllowed", (Standard_Boolean (TDF_Data::*)() const) &TDF_Data::IsModificationAllowed, "returns modification mode.");
cls_TDF_Data.def("LabelNodeAllocator", (const TDF_HAllocator & (TDF_Data::*)() const) &TDF_Data::LabelNodeAllocator, "Returns TDF_HAllocator, which is an incremental allocator used by TDF_LabelNode. This allocator is used to manage TDF_LabelNode objects, but it can also be used for allocating memory to application-specific data (be careful because this allocator does not release the memory). The benefits of this allocation scheme are noticeable when dealing with large OCAF documents, due to: 1. Very quick allocation of objects (memory heap is not used, the algorithm that replaces it is very simple). 2. Very quick destruction of objects (memory is released not by destructors of TDF_LabelNode, but rather by the destructor of TDF_Data). 3. TDF_LabelNode objects do not fragmentize the memory; they are kept compactly in a number of arrays of 16K each. 4. Swapping is reduced on large data, because each document now occupies a smaller number of memory pages.");
cls_TDF_Data.def_static("get_type_name_", (const char * (*)()) &TDF_Data::get_type_name, "None");
cls_TDF_Data.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_Data::get_type_descriptor, "None");
cls_TDF_Data.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_Data::*)() const) &TDF_Data::DynamicType, "None");

// Enums

}