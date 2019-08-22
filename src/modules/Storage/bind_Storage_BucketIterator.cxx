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
#include <Storage_BucketOfPersistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Persistent.hxx>

void bind_Storage_BucketIterator(py::module &mod){

/*
py::class_<Storage_BucketIterator> cls_Storage_BucketIterator(mod, "Storage_BucketIterator", "None");

// Constructors
cls_Storage_BucketIterator.def(py::init<Storage_BucketOfPersistent *>(), py::arg(""));

// Fields

// Methods
cls_Storage_BucketIterator.def("Init", (void (Storage_BucketIterator::*)(Storage_BucketOfPersistent *)) &Storage_BucketIterator::Init, "None", py::arg(""));
cls_Storage_BucketIterator.def("Reset", (void (Storage_BucketIterator::*)()) &Storage_BucketIterator::Reset, "None");
cls_Storage_BucketIterator.def("Value", (Standard_Persistent * (Storage_BucketIterator::*)() const) &Storage_BucketIterator::Value, "None");
cls_Storage_BucketIterator.def("More", (Standard_Boolean (Storage_BucketIterator::*)() const) &Storage_BucketIterator::More, "None");
cls_Storage_BucketIterator.def("Next", (void (Storage_BucketIterator::*)()) &Storage_BucketIterator::Next, "None");

// Enums
*/

}