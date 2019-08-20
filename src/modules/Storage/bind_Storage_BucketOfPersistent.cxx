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
#include <Standard_Handle.hxx>
#include <Standard_Persistent.hxx>

void bind_Storage_BucketOfPersistent(py::module &mod){

/*
py::class_<Storage_BucketOfPersistent, std::unique_ptr<Storage_BucketOfPersistent>> cls_Storage_BucketOfPersistent(mod, "Storage_BucketOfPersistent", "None");

// Constructors
cls_Storage_BucketOfPersistent.def(py::init<>());
cls_Storage_BucketOfPersistent.def(py::init<const Standard_Integer>(), py::arg("theBucketSize"));
cls_Storage_BucketOfPersistent.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theBucketSize"), py::arg("theBucketNumber"));

// Fields

// Methods
cls_Storage_BucketOfPersistent.def("Length", (Standard_Integer (Storage_BucketOfPersistent::*)() const) &Storage_BucketOfPersistent::Length, "None");
cls_Storage_BucketOfPersistent.def("Append", (void (Storage_BucketOfPersistent::*)(const opencascade::handle<Standard_Persistent> &)) &Storage_BucketOfPersistent::Append, "None", py::arg("sp"));
cls_Storage_BucketOfPersistent.def("Value", (Standard_Persistent * (Storage_BucketOfPersistent::*)(const Standard_Integer)) &Storage_BucketOfPersistent::Value, "None", py::arg("theIndex"));
cls_Storage_BucketOfPersistent.def("Clear", (void (Storage_BucketOfPersistent::*)()) &Storage_BucketOfPersistent::Clear, "None");

// Enums
*/

}