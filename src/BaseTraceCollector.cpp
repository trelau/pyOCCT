#include <pyOCCT_Common.hpp>

#include <BaseTraceCollector.hxx>

PYBIND11_MODULE(BaseTraceCollector, mod) {

	// IMPORT

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BaseTraceCollector.hxx
	py::class_<BaseTraceCollector, std::unique_ptr<BaseTraceCollector, Deleter<BaseTraceCollector>>> cls_BaseTraceCollector(mod, "BaseTraceCollector", "See derived Classes in SALOMELocalTrace for usage without CORBA, see derived Classes in SALOMETraceCollector for usage with CORBA.");


}
