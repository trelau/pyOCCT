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
#include <IGESAppli_Array1OfNode.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <IGESAppli_HArray1OfNode.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_HArray1OfNode(py::module &mod){

py::class_<IGESAppli_HArray1OfNode, opencascade::handle<IGESAppli_HArray1OfNode>, Standard_Transient> cls_IGESAppli_HArray1OfNode(mod, "IGESAppli_HArray1OfNode", "None", py::multiple_inheritance());

// Constructors
cls_IGESAppli_HArray1OfNode.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESAppli_HArray1OfNode.def(py::init<const Standard_Integer, const Standard_Integer, const IGESAppli_Array1OfNode::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESAppli_HArray1OfNode.def(py::init<const IGESAppli_Array1OfNode &>(), py::arg("theOther"));

// Fields

// Methods
// cls_IGESAppli_HArray1OfNode.def_static("operator new_", (void * (*)(size_t)) &IGESAppli_HArray1OfNode::operator new, "None", py::arg("theSize"));
// cls_IGESAppli_HArray1OfNode.def_static("operator delete_", (void (*)(void *)) &IGESAppli_HArray1OfNode::operator delete, "None", py::arg("theAddress"));
// cls_IGESAppli_HArray1OfNode.def_static("operator new[]_", (void * (*)(size_t)) &IGESAppli_HArray1OfNode::operator new[], "None", py::arg("theSize"));
// cls_IGESAppli_HArray1OfNode.def_static("operator delete[]_", (void (*)(void *)) &IGESAppli_HArray1OfNode::operator delete[], "None", py::arg("theAddress"));
// cls_IGESAppli_HArray1OfNode.def_static("operator new_", (void * (*)(size_t, void *)) &IGESAppli_HArray1OfNode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESAppli_HArray1OfNode.def_static("operator delete_", (void (*)(void *, void *)) &IGESAppli_HArray1OfNode::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESAppli_HArray1OfNode.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESAppli_HArray1OfNode::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESAppli_HArray1OfNode.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESAppli_HArray1OfNode::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESAppli_HArray1OfNode.def("Array1", (const IGESAppli_Array1OfNode & (IGESAppli_HArray1OfNode::*)() const) &IGESAppli_HArray1OfNode::Array1, "None");
cls_IGESAppli_HArray1OfNode.def("ChangeArray1", (IGESAppli_Array1OfNode & (IGESAppli_HArray1OfNode::*)()) &IGESAppli_HArray1OfNode::ChangeArray1, "None");
cls_IGESAppli_HArray1OfNode.def_static("get_type_name_", (const char * (*)()) &IGESAppli_HArray1OfNode::get_type_name, "None");
cls_IGESAppli_HArray1OfNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_HArray1OfNode::get_type_descriptor, "None");
cls_IGESAppli_HArray1OfNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_HArray1OfNode::*)() const) &IGESAppli_HArray1OfNode::DynamicType, "None");

// Enums

}