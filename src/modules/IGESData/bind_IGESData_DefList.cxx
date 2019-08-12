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
#include <IGESData_DefList.hxx>

void bind_IGESData_DefList(py::module &mod){

py::enum_<IGESData_DefList>(mod, "IGESData_DefList", "Some fields of an IGES entity may be - Undefined - Defined as a single item - Defined as a list of items. A typical example, which presents this kind of variation, is a level number. This enumeration allows you to identify which of the above is the case. The semantics of the terms is as follows: - DefNone indicates that the list is empty (there is not even a single item). - DefOne indicates that the list contains a single item. - DefSeveral indicates that the list contains several items. - ErrorOne indicates that the list contains one item, but that this item is incorrect - ErrorSeveral indicates that the list contains several items, but that at least one of them is incorrect.")
	.value("IGESData_DefNone", IGESData_DefList::IGESData_DefNone)
	.value("IGESData_DefOne", IGESData_DefList::IGESData_DefOne)
	.value("IGESData_DefSeveral", IGESData_DefList::IGESData_DefSeveral)
	.value("IGESData_ErrorOne", IGESData_DefList::IGESData_ErrorOne)
	.value("IGESData_ErrorSeveral", IGESData_DefList::IGESData_ErrorSeveral)
	.export_values();


}