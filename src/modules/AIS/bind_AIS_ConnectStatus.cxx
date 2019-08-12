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
#include <AIS_ConnectStatus.hxx>

void bind_AIS_ConnectStatus(py::module &mod){

py::enum_<AIS_ConnectStatus>(mod, "AIS_ConnectStatus", "Gives the status of connection of an Interactive Object. This will be one of the following: - No connection - Connection - Transformation - Both connection and transformation This enumeration is used in AIS_ConnectedInteractive. Transform indicates that the Interactive Object reference geometry has changed location relative to the reference geometry.")
	.value("AIS_CS_None", AIS_ConnectStatus::AIS_CS_None)
	.value("AIS_CS_Connection", AIS_ConnectStatus::AIS_CS_Connection)
	.value("AIS_CS_Transform", AIS_ConnectStatus::AIS_CS_Transform)
	.value("AIS_CS_Both", AIS_ConnectStatus::AIS_CS_Both)
	.export_values();


}