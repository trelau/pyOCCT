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

#include <NCollection_BaseMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <Plugin_MapOfFunctions.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <Plugin.hxx>
#include <Standard_Failure.hxx>
#include <Standard_SStream.hxx>
#include <Plugin_Failure.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(Plugin, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Plugin.hxx
	py::class_<Plugin, std::unique_ptr<Plugin, Deleter<Plugin>>> cls_Plugin(mod, "Plugin", "None");
	cls_Plugin.def(py::init<>());
	cls_Plugin.def_static("Load_", [](const Standard_GUID & a0) -> opencascade::handle<Standard_Transient> { return Plugin::Load(a0); }, py::arg("aGUID"));
	cls_Plugin.def_static("Load_", (opencascade::handle<Standard_Transient> (*)(const Standard_GUID &, const Standard_Boolean)) &Plugin::Load, "None", py::arg("aGUID"), py::arg("theVerbose"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Plugin_Failure.hxx
	py::class_<Plugin_Failure, opencascade::handle<Plugin_Failure>, Standard_Failure> cls_Plugin_Failure(mod, "Plugin_Failure", "None");
	cls_Plugin_Failure.def(py::init<>());
	cls_Plugin_Failure.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Plugin_Failure.def_static("Raise_", (void (*)(const Standard_CString)) &Plugin_Failure::Raise, "None", py::arg("theMessage"));
	cls_Plugin_Failure.def_static("Raise_", (void (*)(Standard_SStream &)) &Plugin_Failure::Raise, "None", py::arg("theMessage"));
	cls_Plugin_Failure.def_static("NewInstance_", (opencascade::handle<Plugin_Failure> (*)(const Standard_CString)) &Plugin_Failure::NewInstance, "None", py::arg("theMessage"));
	cls_Plugin_Failure.def_static("get_type_name_", (const char * (*)()) &Plugin_Failure::get_type_name, "None");
	cls_Plugin_Failure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Plugin_Failure::get_type_descriptor, "None");
	cls_Plugin_Failure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Plugin_Failure::*)() const ) &Plugin_Failure::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Plugin_MapOfFunctions.hxx
	// FIXME bind_NCollection_DataMap<TCollection_AsciiString, int (*)(...), TCollection_AsciiString>(mod, "Plugin_MapOfFunctions");

	/* FIXME

	*/


}
