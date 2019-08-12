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
#include <Poly_MakeLoops.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>

void bind_Poly_MakeLoops3D(py::module &mod){

py::class_<Poly_MakeLoops3D, std::unique_ptr<Poly_MakeLoops3D, Deleter<Poly_MakeLoops3D>>, Poly_MakeLoops> cls_Poly_MakeLoops3D(mod, "Poly_MakeLoops3D", "None");

// Constructors
cls_Poly_MakeLoops3D.def(py::init<const Poly_MakeLoops3D::Helper *, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theHelper"), py::arg("theAlloc"));

// Fields

// Methods

// Enums

}