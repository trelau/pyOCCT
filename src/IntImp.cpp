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
