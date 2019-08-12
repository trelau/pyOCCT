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
#include <StepBasic_SiUnitName.hxx>

void bind_StepBasic_SiUnitName(py::module &mod){

py::enum_<StepBasic_SiUnitName>(mod, "StepBasic_SiUnitName", "None")
	.value("StepBasic_sunMetre", StepBasic_SiUnitName::StepBasic_sunMetre)
	.value("StepBasic_sunGram", StepBasic_SiUnitName::StepBasic_sunGram)
	.value("StepBasic_sunSecond", StepBasic_SiUnitName::StepBasic_sunSecond)
	.value("StepBasic_sunAmpere", StepBasic_SiUnitName::StepBasic_sunAmpere)
	.value("StepBasic_sunKelvin", StepBasic_SiUnitName::StepBasic_sunKelvin)
	.value("StepBasic_sunMole", StepBasic_SiUnitName::StepBasic_sunMole)
	.value("StepBasic_sunCandela", StepBasic_SiUnitName::StepBasic_sunCandela)
	.value("StepBasic_sunRadian", StepBasic_SiUnitName::StepBasic_sunRadian)
	.value("StepBasic_sunSteradian", StepBasic_SiUnitName::StepBasic_sunSteradian)
	.value("StepBasic_sunHertz", StepBasic_SiUnitName::StepBasic_sunHertz)
	.value("StepBasic_sunNewton", StepBasic_SiUnitName::StepBasic_sunNewton)
	.value("StepBasic_sunPascal", StepBasic_SiUnitName::StepBasic_sunPascal)
	.value("StepBasic_sunJoule", StepBasic_SiUnitName::StepBasic_sunJoule)
	.value("StepBasic_sunWatt", StepBasic_SiUnitName::StepBasic_sunWatt)
	.value("StepBasic_sunCoulomb", StepBasic_SiUnitName::StepBasic_sunCoulomb)
	.value("StepBasic_sunVolt", StepBasic_SiUnitName::StepBasic_sunVolt)
	.value("StepBasic_sunFarad", StepBasic_SiUnitName::StepBasic_sunFarad)
	.value("StepBasic_sunOhm", StepBasic_SiUnitName::StepBasic_sunOhm)
	.value("StepBasic_sunSiemens", StepBasic_SiUnitName::StepBasic_sunSiemens)
	.value("StepBasic_sunWeber", StepBasic_SiUnitName::StepBasic_sunWeber)
	.value("StepBasic_sunTesla", StepBasic_SiUnitName::StepBasic_sunTesla)
	.value("StepBasic_sunHenry", StepBasic_SiUnitName::StepBasic_sunHenry)
	.value("StepBasic_sunDegreeCelsius", StepBasic_SiUnitName::StepBasic_sunDegreeCelsius)
	.value("StepBasic_sunLumen", StepBasic_SiUnitName::StepBasic_sunLumen)
	.value("StepBasic_sunLux", StepBasic_SiUnitName::StepBasic_sunLux)
	.value("StepBasic_sunBecquerel", StepBasic_SiUnitName::StepBasic_sunBecquerel)
	.value("StepBasic_sunGray", StepBasic_SiUnitName::StepBasic_sunGray)
	.value("StepBasic_sunSievert", StepBasic_SiUnitName::StepBasic_sunSievert)
	.export_values();


}