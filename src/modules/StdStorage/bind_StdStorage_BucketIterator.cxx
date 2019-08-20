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
#include <StdStorage_BacketOfPersistent.hxx>
#include <Standard_TypeDef.hxx>
#include <StdObjMgt_Persistent.hxx>

void bind_StdStorage_BucketIterator(py::module &mod){

/*
py::class_<StdStorage_BucketIterator, std::unique_ptr<StdStorage_BucketIterator>> cls_StdStorage_BucketIterator(mod, "StdStorage_BucketIterator", "None");

// Constructors
cls_StdStorage_BucketIterator.def(py::init<StdStorage_BucketOfPersistent *>(), py::arg(""));

// Fields

// Methods
cls_StdStorage_BucketIterator.def("Init", (void (StdStorage_BucketIterator::*)(StdStorage_BucketOfPersistent *)) &StdStorage_BucketIterator::Init, "None", py::arg(""));
cls_StdStorage_BucketIterator.def("Reset", (void (StdStorage_BucketIterator::*)()) &StdStorage_BucketIterator::Reset, "None");
cls_StdStorage_BucketIterator.def("Value", (StdObjMgt_Persistent * (StdStorage_BucketIterator::*)() const) &StdStorage_BucketIterator::Value, "None");
cls_StdStorage_BucketIterator.def("More", (Standard_Boolean (StdStorage_BucketIterator::*)() const) &StdStorage_BucketIterator::More, "None");
cls_StdStorage_BucketIterator.def("Next", (void (StdStorage_BucketIterator::*)()) &StdStorage_BucketIterator::Next, "None");

// Enums
*/

}