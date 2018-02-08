/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <IntImp_ConstIsoparametric.hxx>
#include <IntImp_ComputeTangence.hxx>
#include <Standard_TypeDef.hxx>

PYBIND11_MODULE(IntImp, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntImp_ConstIsoparametric.hxx
	py::enum_<IntImp_ConstIsoparametric>(mod, "IntImp_ConstIsoparametric", "None")
		.value("IntImp_UIsoparametricOnCaro1", IntImp_ConstIsoparametric::IntImp_UIsoparametricOnCaro1)
		.value("IntImp_VIsoparametricOnCaro1", IntImp_ConstIsoparametric::IntImp_VIsoparametricOnCaro1)
		.value("IntImp_UIsoparametricOnCaro2", IntImp_ConstIsoparametric::IntImp_UIsoparametricOnCaro2)
		.value("IntImp_VIsoparametricOnCaro2", IntImp_ConstIsoparametric::IntImp_VIsoparametricOnCaro2)
		.export_values();

	// FUNCTIONS
	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntImp_ComputeTangence.hxx
	mod.def("IntImp_ComputeTangence", (Standard_Boolean (*)(const gp_Vec [], const Standard_Real [], Standard_Real [], IntImp_ConstIsoparametric [])) &IntImp_ComputeTangence, "None", py::arg("DPuv"), py::arg("EpsUV"), py::arg("Tgduv"), py::arg("TabIso"));
	*/

	// CLASSES

}
