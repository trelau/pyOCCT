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
#include <FEmTool_AssemblyTable.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array2.hxx>
#include <FEmTool_HAssemblyTable.hxx>
#include <Standard_Type.hxx>

void bind_FEmTool_HAssemblyTable(py::module &mod){

py::class_<FEmTool_HAssemblyTable, opencascade::handle<FEmTool_HAssemblyTable>, Standard_Transient> cls_FEmTool_HAssemblyTable(mod, "FEmTool_HAssemblyTable", "None", py::multiple_inheritance());

// Constructors
cls_FEmTool_HAssemblyTable.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_FEmTool_HAssemblyTable.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const FEmTool_AssemblyTable::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_FEmTool_HAssemblyTable.def(py::init<const FEmTool_AssemblyTable &>(), py::arg("theOther"));

// Fields

// Methods
// cls_FEmTool_HAssemblyTable.def_static("operator new_", (void * (*)(size_t)) &FEmTool_HAssemblyTable::operator new, "None", py::arg("theSize"));
// cls_FEmTool_HAssemblyTable.def_static("operator delete_", (void (*)(void *)) &FEmTool_HAssemblyTable::operator delete, "None", py::arg("theAddress"));
// cls_FEmTool_HAssemblyTable.def_static("operator new[]_", (void * (*)(size_t)) &FEmTool_HAssemblyTable::operator new[], "None", py::arg("theSize"));
// cls_FEmTool_HAssemblyTable.def_static("operator delete[]_", (void (*)(void *)) &FEmTool_HAssemblyTable::operator delete[], "None", py::arg("theAddress"));
// cls_FEmTool_HAssemblyTable.def_static("operator new_", (void * (*)(size_t, void *)) &FEmTool_HAssemblyTable::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FEmTool_HAssemblyTable.def_static("operator delete_", (void (*)(void *, void *)) &FEmTool_HAssemblyTable::operator delete, "None", py::arg(""), py::arg(""));
// cls_FEmTool_HAssemblyTable.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &FEmTool_HAssemblyTable::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_FEmTool_HAssemblyTable.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &FEmTool_HAssemblyTable::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_FEmTool_HAssemblyTable.def("Array2", (const FEmTool_AssemblyTable & (FEmTool_HAssemblyTable::*)() const) &FEmTool_HAssemblyTable::Array2, "None");
cls_FEmTool_HAssemblyTable.def("ChangeArray2", (FEmTool_AssemblyTable & (FEmTool_HAssemblyTable::*)()) &FEmTool_HAssemblyTable::ChangeArray2, "None");
cls_FEmTool_HAssemblyTable.def_static("get_type_name_", (const char * (*)()) &FEmTool_HAssemblyTable::get_type_name, "None");
cls_FEmTool_HAssemblyTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_HAssemblyTable::get_type_descriptor, "None");
cls_FEmTool_HAssemblyTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_HAssemblyTable::*)() const) &FEmTool_HAssemblyTable::DynamicType, "None");

// Enums

}