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
#include <Standard_Assert.hxx>

void bind_Standard_Static_Assert(py::module &mod){

py::class_<Standard_Static_Assert<true>> cls_Standard_Static_Assert(mod, "Standard_Static_Assert", "Static assert -- specialization for condition being true");

// Constructors

// Fields

// Methods
cls_Standard_Static_Assert.def_static("assert_ok_", (void (*)()) &Standard_Static_Assert<true>::assert_ok, "None");

// Enums

}