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
#ifndef __IMeshData_ParametersListArrayAdaptor__
#define __IMeshData_ParametersListArrayAdaptor__

#include <Standard_Transient.hxx>
#include <IMeshData_ParametersListArrayAdaptor.hxx>
#include <Standard_TypeDef.hxx>

template <typename ParametersListPtrType>
void bind_IMeshData_ParametersListArrayAdaptor(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<IMeshData_ParametersListArrayAdaptor<ParametersListPtrType>, opencascade::handle<IMeshData_ParametersListArrayAdaptor<ParametersListPtrType>>, Standard_Transient> cls_IMeshData_ParametersListArrayAdaptor(mod, name.c_str(), "Auxiliary tool representing adaptor interface for child classes of IMeshData_ParametersList to be used in tools working on NCollection_Array structure.", local);

// Constructors
cls_IMeshData_ParametersListArrayAdaptor.def(py::init<const ParametersListPtrType &>(), py::arg("theParameters"));

// Methods
cls_IMeshData_ParametersListArrayAdaptor.def("Lower", (Standard_Integer (IMeshData_ParametersListArrayAdaptor<ParametersListPtrType>::*)() const) &IMeshData_ParametersListArrayAdaptor<ParametersListPtrType>::Lower, "Returns lower index in parameters array.");
cls_IMeshData_ParametersListArrayAdaptor.def("Upper", (Standard_Integer (IMeshData_ParametersListArrayAdaptor<ParametersListPtrType>::*)() const) &IMeshData_ParametersListArrayAdaptor<ParametersListPtrType>::Upper, "Returns upper index in parameters array.");
cls_IMeshData_ParametersListArrayAdaptor.def("Value", (Standard_Real (IMeshData_ParametersListArrayAdaptor<ParametersListPtrType>::*)(const Standard_Integer) const) &IMeshData_ParametersListArrayAdaptor<ParametersListPtrType>::Value, "Returns value of the given index.", py::arg("theIndex"));

}

#endif