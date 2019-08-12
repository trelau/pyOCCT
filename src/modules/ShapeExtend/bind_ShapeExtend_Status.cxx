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
#include <ShapeExtend_Status.hxx>

void bind_ShapeExtend_Status(py::module &mod){

py::enum_<ShapeExtend_Status>(mod, "ShapeExtend_Status", "This enumeration is used in ShapeHealing toolkit for representing flags in the return statuses of class methods. The status is a field of the class which is set by one or several methods of that class. It is used for reporting about errors and other situations encountered during execution of the method. There are defined 8 values for DONE and 8 for FAIL flags: ShapeExtend_DONE1 ... ShapeExtend_DONE8, ShapeExtend_FAIL1 ... ShapeExtend_FAIL8 and also enumerations for representing combinations of flags: ShapeExtend_OK - no flags at all, ShapeExtend_DONE - any of flags DONEi, ShapeExtend_FAIL - any of flags FAILi. The class that uses statuses provides a method(s) which answers whether the flag corresponding to a given enumerative value is (are) set: Standard_Boolean Status(const ShapeExtend_Status test); Note that status can have several flags set simultaneously. Status(ShapeExtend_OK) gives True when no flags are set. Nothing done, everything OK Something was done, case 1 Something was done, case 2 Something was done, case 3 Something was done, case 4 Something was done, case 5 Something was done, case 6 Something was done, case 7 Something was done, case 8 Something was done (any of DONE#) The method failed, case 1 The method failed, case 2 The method failed, case 3 The method failed, case 4 The method failed, case 5 The method failed, case 6 The method failed, case 7 The method failed, case 8 The mathod failed (any of FAIL# occured)")
	.value("ShapeExtend_OK", ShapeExtend_Status::ShapeExtend_OK)
	.value("ShapeExtend_DONE1", ShapeExtend_Status::ShapeExtend_DONE1)
	.value("ShapeExtend_DONE2", ShapeExtend_Status::ShapeExtend_DONE2)
	.value("ShapeExtend_DONE3", ShapeExtend_Status::ShapeExtend_DONE3)
	.value("ShapeExtend_DONE4", ShapeExtend_Status::ShapeExtend_DONE4)
	.value("ShapeExtend_DONE5", ShapeExtend_Status::ShapeExtend_DONE5)
	.value("ShapeExtend_DONE6", ShapeExtend_Status::ShapeExtend_DONE6)
	.value("ShapeExtend_DONE7", ShapeExtend_Status::ShapeExtend_DONE7)
	.value("ShapeExtend_DONE8", ShapeExtend_Status::ShapeExtend_DONE8)
	.value("ShapeExtend_DONE", ShapeExtend_Status::ShapeExtend_DONE)
	.value("ShapeExtend_FAIL1", ShapeExtend_Status::ShapeExtend_FAIL1)
	.value("ShapeExtend_FAIL2", ShapeExtend_Status::ShapeExtend_FAIL2)
	.value("ShapeExtend_FAIL3", ShapeExtend_Status::ShapeExtend_FAIL3)
	.value("ShapeExtend_FAIL4", ShapeExtend_Status::ShapeExtend_FAIL4)
	.value("ShapeExtend_FAIL5", ShapeExtend_Status::ShapeExtend_FAIL5)
	.value("ShapeExtend_FAIL6", ShapeExtend_Status::ShapeExtend_FAIL6)
	.value("ShapeExtend_FAIL7", ShapeExtend_Status::ShapeExtend_FAIL7)
	.value("ShapeExtend_FAIL8", ShapeExtend_Status::ShapeExtend_FAIL8)
	.value("ShapeExtend_FAIL", ShapeExtend_Status::ShapeExtend_FAIL)
	.export_values();


}