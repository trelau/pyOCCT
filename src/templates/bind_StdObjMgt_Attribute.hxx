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
#ifndef __StdObjMgt_Attribute__
#define __StdObjMgt_Attribute__

#include <Standard_Transient.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <StdObjMgt_Attribute.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <Standard_TypeDef.hxx>

template <typename Transient>
void bind_StdObjMgt_Attribute(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<StdObjMgt_Attribute<Transient>, opencascade::handle<StdObjMgt_Attribute<Transient>>, Standard_Transient> cls_StdObjMgt_Attribute(mod, name.c_str(), "Root class for a temporary persistent object corresponding to an attribute.", local);

}

#endif