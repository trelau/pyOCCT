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
#include <UnitsAPI_SystemUnits.hxx>

void bind_UnitsAPI_SystemUnits(py::module &mod){

py::enum_<UnitsAPI_SystemUnits>(mod, "UnitsAPI_SystemUnits", "Identifies unit systems which may be defined as a basis system in the user's session: - UnitsAPI_DEFAULT : default system (this is the SI system) - UnitsAPI_SI : the SI unit system - UnitsAPI_MDTV : the MDTV unit system; it is equivalent to the SI unit system but the length unit and all its derivatives use millimeters instead of meters. Use the function SetLocalSystem to set up one of these unit systems as working environment.")
	.value("UnitsAPI_DEFAULT", UnitsAPI_SystemUnits::UnitsAPI_DEFAULT)
	.value("UnitsAPI_SI", UnitsAPI_SystemUnits::UnitsAPI_SI)
	.value("UnitsAPI_MDTV", UnitsAPI_SystemUnits::UnitsAPI_MDTV)
	.export_values();


}