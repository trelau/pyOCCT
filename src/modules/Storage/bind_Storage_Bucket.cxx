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
#include <Storage_Schema.hxx>
#include <Standard_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard.hxx>

void bind_Storage_Bucket(py::module &mod){

/*
py::class_<Storage_Bucket> cls_Storage_Bucket(mod, "Storage_Bucket", "None");

// Constructors
cls_Storage_Bucket.def(py::init<>());
cls_Storage_Bucket.def(py::init<const Standard_Integer>(), py::arg("theSpaceSize"));

// Fields

// Methods
cls_Storage_Bucket.def("Clear", (void (Storage_Bucket::*)()) &Storage_Bucket::Clear, "None");

// Enums
*/

}