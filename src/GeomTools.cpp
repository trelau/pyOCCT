#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <Message_ProgressIndicator.hxx>
#include <GeomTools_SurfaceSet.hxx>
#include <Geom_Curve.hxx>
#include <GeomTools_CurveSet.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomTools_Curve2dSet.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <GeomTools_UndefinedTypeHandler.hxx>
#include <GeomTools.hxx>

PYBIND11_MODULE(GeomTools, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.Geom2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomTools_SurfaceSet.hxx
	py::class_<GeomTools_SurfaceSet, std::unique_ptr<GeomTools_SurfaceSet, Deleter<GeomTools_SurfaceSet>>> cls_GeomTools_SurfaceSet(mod, "GeomTools_SurfaceSet", "Stores a set of Surfaces from Geom.");
	cls_GeomTools_SurfaceSet.def(py::init<>());
	cls_GeomTools_SurfaceSet.def("Clear", (void (GeomTools_SurfaceSet::*)()) &GeomTools_SurfaceSet::Clear, "Clears the content of the set.");
	cls_GeomTools_SurfaceSet.def("Add", (Standard_Integer (GeomTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &)) &GeomTools_SurfaceSet::Add, "Incorporate a new Surface in the set and returns its index.", py::arg("S"));
	cls_GeomTools_SurfaceSet.def("Surface", (opencascade::handle<Geom_Surface> (GeomTools_SurfaceSet::*)(const Standard_Integer) const ) &GeomTools_SurfaceSet::Surface, "Returns the Surface of index <I>.", py::arg("I"));
	cls_GeomTools_SurfaceSet.def("Index", (Standard_Integer (GeomTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &) const ) &GeomTools_SurfaceSet::Index, "Returns the index of <L>.", py::arg("S"));
	// FIXME cls_GeomTools_SurfaceSet.def("Dump", (void (GeomTools_SurfaceSet::*)(Standard_OStream &) const ) &GeomTools_SurfaceSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
	cls_GeomTools_SurfaceSet.def("Write", (void (GeomTools_SurfaceSet::*)(Standard_OStream &) const ) &GeomTools_SurfaceSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_GeomTools_SurfaceSet.def("Read", (void (GeomTools_SurfaceSet::*)(Standard_IStream &)) &GeomTools_SurfaceSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
	cls_GeomTools_SurfaceSet.def_static("PrintSurface_", [](const opencascade::handle<Geom_Surface> & a0, Standard_OStream & a1) -> void { return GeomTools_SurfaceSet::PrintSurface(a0, a1); }, py::arg("S"), py::arg("OS"));
	cls_GeomTools_SurfaceSet.def_static("PrintSurface_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &, const Standard_Boolean)) &GeomTools_SurfaceSet::PrintSurface, "Dumps the surface on the stream, if compact is True use the compact format that can be read back.", py::arg("S"), py::arg("OS"), py::arg("compact"));
	cls_GeomTools_SurfaceSet.def_static("ReadSurface_", (opencascade::handle<Geom_Surface> (*)(Standard_IStream &)) &GeomTools_SurfaceSet::ReadSurface, "Reads the surface from the stream. The surface is assumed to have been written with the Print method (compact = True).", py::arg("IS"));
	cls_GeomTools_SurfaceSet.def("SetProgress", (void (GeomTools_SurfaceSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &GeomTools_SurfaceSet::SetProgress, "None", py::arg("PR"));
	cls_GeomTools_SurfaceSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (GeomTools_SurfaceSet::*)() const ) &GeomTools_SurfaceSet::GetProgress, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomTools_CurveSet.hxx
	py::class_<GeomTools_CurveSet, std::unique_ptr<GeomTools_CurveSet, Deleter<GeomTools_CurveSet>>> cls_GeomTools_CurveSet(mod, "GeomTools_CurveSet", "Stores a set of Curves from Geom.");
	cls_GeomTools_CurveSet.def(py::init<>());
	cls_GeomTools_CurveSet.def("Clear", (void (GeomTools_CurveSet::*)()) &GeomTools_CurveSet::Clear, "Clears the content of the set.");
	cls_GeomTools_CurveSet.def("Add", (Standard_Integer (GeomTools_CurveSet::*)(const opencascade::handle<Geom_Curve> &)) &GeomTools_CurveSet::Add, "Incorporate a new Curve in the set and returns its index.", py::arg("C"));
	cls_GeomTools_CurveSet.def("Curve", (opencascade::handle<Geom_Curve> (GeomTools_CurveSet::*)(const Standard_Integer) const ) &GeomTools_CurveSet::Curve, "Returns the Curve of index <I>.", py::arg("I"));
	cls_GeomTools_CurveSet.def("Index", (Standard_Integer (GeomTools_CurveSet::*)(const opencascade::handle<Geom_Curve> &) const ) &GeomTools_CurveSet::Index, "Returns the index of <L>.", py::arg("C"));
	// FIXME cls_GeomTools_CurveSet.def("Dump", (void (GeomTools_CurveSet::*)(Standard_OStream &) const ) &GeomTools_CurveSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
	cls_GeomTools_CurveSet.def("Write", (void (GeomTools_CurveSet::*)(Standard_OStream &) const ) &GeomTools_CurveSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_GeomTools_CurveSet.def("Read", (void (GeomTools_CurveSet::*)(Standard_IStream &)) &GeomTools_CurveSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
	cls_GeomTools_CurveSet.def_static("PrintCurve_", [](const opencascade::handle<Geom_Curve> & a0, Standard_OStream & a1) -> void { return GeomTools_CurveSet::PrintCurve(a0, a1); }, py::arg("C"), py::arg("OS"));
	cls_GeomTools_CurveSet.def_static("PrintCurve_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &, const Standard_Boolean)) &GeomTools_CurveSet::PrintCurve, "Dumps the curve on the stream, if compact is True use the compact format that can be read back.", py::arg("C"), py::arg("OS"), py::arg("compact"));
	cls_GeomTools_CurveSet.def_static("ReadCurve_", (opencascade::handle<Geom_Curve> (*)(Standard_IStream &)) &GeomTools_CurveSet::ReadCurve, "Reads the curve from the stream. The curve is assumed to have been written with the Print method (compact = True).", py::arg("IS"));
	cls_GeomTools_CurveSet.def("SetProgress", (void (GeomTools_CurveSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &GeomTools_CurveSet::SetProgress, "None", py::arg("PR"));
	cls_GeomTools_CurveSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (GeomTools_CurveSet::*)() const ) &GeomTools_CurveSet::GetProgress, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomTools_Curve2dSet.hxx
	py::class_<GeomTools_Curve2dSet, std::unique_ptr<GeomTools_Curve2dSet, Deleter<GeomTools_Curve2dSet>>> cls_GeomTools_Curve2dSet(mod, "GeomTools_Curve2dSet", "Stores a set of Curves from Geom2d.");
	cls_GeomTools_Curve2dSet.def(py::init<>());
	cls_GeomTools_Curve2dSet.def("Clear", (void (GeomTools_Curve2dSet::*)()) &GeomTools_Curve2dSet::Clear, "Clears the content of the set.");
	cls_GeomTools_Curve2dSet.def("Add", (Standard_Integer (GeomTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &)) &GeomTools_Curve2dSet::Add, "Incorporate a new Curve in the set and returns its index.", py::arg("C"));
	cls_GeomTools_Curve2dSet.def("Curve2d", (opencascade::handle<Geom2d_Curve> (GeomTools_Curve2dSet::*)(const Standard_Integer) const ) &GeomTools_Curve2dSet::Curve2d, "Returns the Curve of index <I>.", py::arg("I"));
	cls_GeomTools_Curve2dSet.def("Index", (Standard_Integer (GeomTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &) const ) &GeomTools_Curve2dSet::Index, "Returns the index of <L>.", py::arg("C"));
	// FIXME cls_GeomTools_Curve2dSet.def("Dump", (void (GeomTools_Curve2dSet::*)(Standard_OStream &) const ) &GeomTools_Curve2dSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
	cls_GeomTools_Curve2dSet.def("Write", (void (GeomTools_Curve2dSet::*)(Standard_OStream &) const ) &GeomTools_Curve2dSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_GeomTools_Curve2dSet.def("Read", (void (GeomTools_Curve2dSet::*)(Standard_IStream &)) &GeomTools_Curve2dSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
	cls_GeomTools_Curve2dSet.def_static("PrintCurve2d_", [](const opencascade::handle<Geom2d_Curve> & a0, Standard_OStream & a1) -> void { return GeomTools_Curve2dSet::PrintCurve2d(a0, a1); }, py::arg("C"), py::arg("OS"));
	cls_GeomTools_Curve2dSet.def_static("PrintCurve2d_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &, const Standard_Boolean)) &GeomTools_Curve2dSet::PrintCurve2d, "Dumps the curve on the stream, if compact is True use the compact format that can be read back.", py::arg("C"), py::arg("OS"), py::arg("compact"));
	cls_GeomTools_Curve2dSet.def_static("ReadCurve2d_", (opencascade::handle<Geom2d_Curve> (*)(Standard_IStream &)) &GeomTools_Curve2dSet::ReadCurve2d, "Reads the curve from the stream. The curve is assumed to have been written with the Print method (compact = True).", py::arg("IS"));
	cls_GeomTools_Curve2dSet.def("SetProgress", (void (GeomTools_Curve2dSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &GeomTools_Curve2dSet::SetProgress, "None", py::arg("PR"));
	cls_GeomTools_Curve2dSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (GeomTools_Curve2dSet::*)() const ) &GeomTools_Curve2dSet::GetProgress, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomTools_UndefinedTypeHandler.hxx
	py::class_<GeomTools_UndefinedTypeHandler, opencascade::handle<GeomTools_UndefinedTypeHandler>, Standard_Transient> cls_GeomTools_UndefinedTypeHandler(mod, "GeomTools_UndefinedTypeHandler", "None");
	cls_GeomTools_UndefinedTypeHandler.def(py::init<>());
	cls_GeomTools_UndefinedTypeHandler.def("PrintCurve", [](GeomTools_UndefinedTypeHandler &self, const opencascade::handle<Geom_Curve> & a0, Standard_OStream & a1) -> void { return self.PrintCurve(a0, a1); }, py::arg("C"), py::arg("OS"));
	cls_GeomTools_UndefinedTypeHandler.def("PrintCurve", (void (GeomTools_UndefinedTypeHandler::*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &, const Standard_Boolean) const ) &GeomTools_UndefinedTypeHandler::PrintCurve, "None", py::arg("C"), py::arg("OS"), py::arg("compact"));
	cls_GeomTools_UndefinedTypeHandler.def("ReadCurve", (Standard_IStream & (GeomTools_UndefinedTypeHandler::*)(const Standard_Integer, Standard_IStream &, opencascade::handle<Geom_Curve> &) const ) &GeomTools_UndefinedTypeHandler::ReadCurve, "None", py::arg("ctype"), py::arg("IS"), py::arg("C"));
	cls_GeomTools_UndefinedTypeHandler.def("PrintCurve2d", [](GeomTools_UndefinedTypeHandler &self, const opencascade::handle<Geom2d_Curve> & a0, Standard_OStream & a1) -> void { return self.PrintCurve2d(a0, a1); }, py::arg("C"), py::arg("OS"));
	cls_GeomTools_UndefinedTypeHandler.def("PrintCurve2d", (void (GeomTools_UndefinedTypeHandler::*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &, const Standard_Boolean) const ) &GeomTools_UndefinedTypeHandler::PrintCurve2d, "None", py::arg("C"), py::arg("OS"), py::arg("compact"));
	cls_GeomTools_UndefinedTypeHandler.def("ReadCurve2d", (Standard_IStream & (GeomTools_UndefinedTypeHandler::*)(const Standard_Integer, Standard_IStream &, opencascade::handle<Geom2d_Curve> &) const ) &GeomTools_UndefinedTypeHandler::ReadCurve2d, "None", py::arg("ctype"), py::arg("IS"), py::arg("C"));
	cls_GeomTools_UndefinedTypeHandler.def("PrintSurface", [](GeomTools_UndefinedTypeHandler &self, const opencascade::handle<Geom_Surface> & a0, Standard_OStream & a1) -> void { return self.PrintSurface(a0, a1); }, py::arg("S"), py::arg("OS"));
	cls_GeomTools_UndefinedTypeHandler.def("PrintSurface", (void (GeomTools_UndefinedTypeHandler::*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &, const Standard_Boolean) const ) &GeomTools_UndefinedTypeHandler::PrintSurface, "None", py::arg("S"), py::arg("OS"), py::arg("compact"));
	cls_GeomTools_UndefinedTypeHandler.def("ReadSurface", (Standard_IStream & (GeomTools_UndefinedTypeHandler::*)(const Standard_Integer, Standard_IStream &, opencascade::handle<Geom_Surface> &) const ) &GeomTools_UndefinedTypeHandler::ReadSurface, "None", py::arg("ctype"), py::arg("IS"), py::arg("S"));
	cls_GeomTools_UndefinedTypeHandler.def_static("get_type_name_", (const char * (*)()) &GeomTools_UndefinedTypeHandler::get_type_name, "None");
	cls_GeomTools_UndefinedTypeHandler.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomTools_UndefinedTypeHandler::get_type_descriptor, "None");
	cls_GeomTools_UndefinedTypeHandler.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomTools_UndefinedTypeHandler::*)() const ) &GeomTools_UndefinedTypeHandler::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomTools.hxx
	py::class_<GeomTools, std::unique_ptr<GeomTools, Deleter<GeomTools>>> cls_GeomTools(mod, "GeomTools", "The GeomTools package provides utilities for Geometry.");
	cls_GeomTools.def(py::init<>());
	// FIXME cls_GeomTools.def_static("Dump_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &)) &GeomTools::Dump, "A set of Curves from Geom2d. Dumps the surface on the stream.", py::arg("S"), py::arg("OS"));
	cls_GeomTools.def_static("Write_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &)) &GeomTools::Write, "Writes the surface on the stream.", py::arg("S"), py::arg("OS"));
	cls_GeomTools.def_static("Read_", (void (*)(opencascade::handle<Geom_Surface> &, Standard_IStream &)) &GeomTools::Read, "Reads the surface from the stream.", py::arg("S"), py::arg("IS"));
	// FIXME cls_GeomTools.def_static("Dump_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &)) &GeomTools::Dump, "Dumps the Curve on the stream.", py::arg("C"), py::arg("OS"));
	cls_GeomTools.def_static("Write_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &)) &GeomTools::Write, "Writes the Curve on the stream.", py::arg("C"), py::arg("OS"));
	cls_GeomTools.def_static("Read_", (void (*)(opencascade::handle<Geom_Curve> &, Standard_IStream &)) &GeomTools::Read, "Reads the Curve from the stream.", py::arg("C"), py::arg("IS"));
	// FIXME cls_GeomTools.def_static("Dump_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &)) &GeomTools::Dump, "Dumps the Curve on the stream.", py::arg("C"), py::arg("OS"));
	cls_GeomTools.def_static("Write_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &)) &GeomTools::Write, "Writes the Curve on the stream.", py::arg("C"), py::arg("OS"));
	cls_GeomTools.def_static("Read_", (void (*)(opencascade::handle<Geom2d_Curve> &, Standard_IStream &)) &GeomTools::Read, "Reads the Curve from the stream.", py::arg("C"), py::arg("IS"));
	cls_GeomTools.def_static("SetUndefinedTypeHandler_", (void (*)(const opencascade::handle<GeomTools_UndefinedTypeHandler> &)) &GeomTools::SetUndefinedTypeHandler, "None", py::arg("aHandler"));
	cls_GeomTools.def_static("GetUndefinedTypeHandler_", (opencascade::handle<GeomTools_UndefinedTypeHandler> (*)()) &GeomTools::GetUndefinedTypeHandler, "None");
	cls_GeomTools.def_static("GetReal_", [](Standard_IStream & IS, Standard_Real & theValue){ GeomTools::GetReal(IS, theValue); return theValue; }, "Reads the Standard_Real value from the stream. Zero is read in case of error", py::arg("IS"), py::arg("theValue"));


}
