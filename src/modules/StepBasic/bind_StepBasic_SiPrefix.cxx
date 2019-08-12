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
#include <StepBasic_SiPrefix.hxx>

void bind_StepBasic_SiPrefix(py::module &mod){

py::enum_<StepBasic_SiPrefix>(mod, "StepBasic_SiPrefix", "None")
	.value("StepBasic_spExa", StepBasic_SiPrefix::StepBasic_spExa)
	.value("StepBasic_spPeta", StepBasic_SiPrefix::StepBasic_spPeta)
	.value("StepBasic_spTera", StepBasic_SiPrefix::StepBasic_spTera)
	.value("StepBasic_spGiga", StepBasic_SiPrefix::StepBasic_spGiga)
	.value("StepBasic_spMega", StepBasic_SiPrefix::StepBasic_spMega)
	.value("StepBasic_spKilo", StepBasic_SiPrefix::StepBasic_spKilo)
	.value("StepBasic_spHecto", StepBasic_SiPrefix::StepBasic_spHecto)
	.value("StepBasic_spDeca", StepBasic_SiPrefix::StepBasic_spDeca)
	.value("StepBasic_spDeci", StepBasic_SiPrefix::StepBasic_spDeci)
	.value("StepBasic_spCenti", StepBasic_SiPrefix::StepBasic_spCenti)
	.value("StepBasic_spMilli", StepBasic_SiPrefix::StepBasic_spMilli)
	.value("StepBasic_spMicro", StepBasic_SiPrefix::StepBasic_spMicro)
	.value("StepBasic_spNano", StepBasic_SiPrefix::StepBasic_spNano)
	.value("StepBasic_spPico", StepBasic_SiPrefix::StepBasic_spPico)
	.value("StepBasic_spFemto", StepBasic_SiPrefix::StepBasic_spFemto)
	.value("StepBasic_spAtto", StepBasic_SiPrefix::StepBasic_spAtto)
	.export_values();


}