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
#include <IGESData_DefType.hxx>

void bind_IGESData_DefType(py::module &mod){

py::enum_<IGESData_DefType>(mod, "IGESData_DefType", "Some fields of an IGES entity may be - Undefined - Defined as a positive integer - Defined as a reference to a specialized entity. A typical example of this kind of variation is color. This enumeration allows you to identify which of the above is the case. The semantics of the terms are as follows: - DefVoid indicates that the item contained in the field is undefined - DefValue indicates that the item is defined as an immediate positive integer value (i.e. not a pointer) - DefReference indicates that the item is defined as an entity - DefAny indicates the item could not be determined - ErrorVal indicates that the item is defined as an integer but its value is incorrect (it could be out of range, for example) - ErrorRef indicates that the item is defined as an entity but is not of the required type.")
	.value("IGESData_DefVoid", IGESData_DefType::IGESData_DefVoid)
	.value("IGESData_DefValue", IGESData_DefType::IGESData_DefValue)
	.value("IGESData_DefReference", IGESData_DefType::IGESData_DefReference)
	.value("IGESData_DefAny", IGESData_DefType::IGESData_DefAny)
	.value("IGESData_ErrorVal", IGESData_DefType::IGESData_ErrorVal)
	.value("IGESData_ErrorRef", IGESData_DefType::IGESData_ErrorRef)
	.export_values();


}