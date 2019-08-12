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
#include <Interface_DataState.hxx>

void bind_Interface_DataState(py::module &mod){

py::enum_<Interface_DataState>(mod, "Interface_DataState", "validity state of anentity's content (see InterfaceModel)")
	.value("Interface_StateOK", Interface_DataState::Interface_StateOK)
	.value("Interface_LoadWarning", Interface_DataState::Interface_LoadWarning)
	.value("Interface_LoadFail", Interface_DataState::Interface_LoadFail)
	.value("Interface_DataWarning", Interface_DataState::Interface_DataWarning)
	.value("Interface_DataFail", Interface_DataState::Interface_DataFail)
	.value("Interface_StateUnloaded", Interface_DataState::Interface_StateUnloaded)
	.value("Interface_StateUnknown", Interface_DataState::Interface_StateUnknown)
	.export_values();


}