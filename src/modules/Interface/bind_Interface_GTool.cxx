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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_SignType.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_GeneralLib.hxx>
#include <Interface_GeneralModule.hxx>
#include <Interface_GTool.hxx>
#include <Standard_Type.hxx>
#include <Interface_DataMapOfTransientInteger.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>

void bind_Interface_GTool(py::module &mod){

py::class_<Interface_GTool, opencascade::handle<Interface_GTool>, Standard_Transient> cls_Interface_GTool(mod, "Interface_GTool", "GTool - General Tool for a Model Provides the functions performed by Protocol/GeneralModule for entities of a Model, and recorded in a GeneralLib Optimized : once an entity has been queried, the GeneralLib is not longer queried Shareable between several users : as a Handle");

// Constructors
cls_Interface_GTool.def(py::init<>());
cls_Interface_GTool.def(py::init<const opencascade::handle<Interface_Protocol> &>(), py::arg("proto"));
cls_Interface_GTool.def(py::init<const opencascade::handle<Interface_Protocol> &, const Standard_Integer>(), py::arg("proto"), py::arg("nbent"));

// Fields

// Methods
cls_Interface_GTool.def("SetSignType", (void (Interface_GTool::*)(const opencascade::handle<Interface_SignType> &)) &Interface_GTool::SetSignType, "Sets a new SignType", py::arg("sign"));
cls_Interface_GTool.def("SignType", (opencascade::handle<Interface_SignType> (Interface_GTool::*)() const) &Interface_GTool::SignType, "Returns the SignType. Can be null");
cls_Interface_GTool.def("SignValue", (Standard_CString (Interface_GTool::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &Interface_GTool::SignValue, "Returns the Signature for a Transient Object in a Model It calls SignType to do that If SignType is not defined, return ClassName of <ent>", py::arg("ent"), py::arg("model"));
cls_Interface_GTool.def("SignName", (Standard_CString (Interface_GTool::*)() const) &Interface_GTool::SignName, "Returns the Name of the SignType, or 'Class Name'");
cls_Interface_GTool.def("SetProtocol", [](Interface_GTool &self, const opencascade::handle<Interface_Protocol> & a0) -> void { return self.SetProtocol(a0); });
cls_Interface_GTool.def("SetProtocol", (void (Interface_GTool::*)(const opencascade::handle<Interface_Protocol> &, const Standard_Boolean)) &Interface_GTool::SetProtocol, "Sets a new Protocol if <enforce> is False and the new Protocol equates the old one then nothing is done", py::arg("proto"), py::arg("enforce"));
cls_Interface_GTool.def("Protocol", (opencascade::handle<Interface_Protocol> (Interface_GTool::*)() const) &Interface_GTool::Protocol, "Returns the Protocol. Warning : it can be Null");
cls_Interface_GTool.def("Lib", (Interface_GeneralLib & (Interface_GTool::*)()) &Interface_GTool::Lib, "Returns the GeneralLib itself");
cls_Interface_GTool.def("Reservate", [](Interface_GTool &self, const Standard_Integer a0) -> void { return self.Reservate(a0); });
cls_Interface_GTool.def("Reservate", (void (Interface_GTool::*)(const Standard_Integer, const Standard_Boolean)) &Interface_GTool::Reservate, "Reservates maps for a count of entities <enforce> False : minimum count <enforce> True : clears former reservations Does not clear the maps", py::arg("nb"), py::arg("enforce"));
cls_Interface_GTool.def("ClearEntities", (void (Interface_GTool::*)()) &Interface_GTool::ClearEntities, "Clears the maps which record, for each already recorded entity its Module and Case Number");
cls_Interface_GTool.def("Select", [](Interface_GTool &self, const opencascade::handle<Standard_Transient> & ent, opencascade::handle<Interface_GeneralModule> & gmod, Standard_Integer & CN, const Standard_Boolean enforce){ Standard_Boolean rv = self.Select(ent, gmod, CN, enforce); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, CN); }, "Selects for an entity, its Module and Case Number It is optimised : once done for each entity, the result is mapped and the GeneralLib is not longer queried <enforce> True overpasses this optimisation", py::arg("ent"), py::arg("gmod"), py::arg("CN"), py::arg("enforce"));
cls_Interface_GTool.def_static("get_type_name_", (const char * (*)()) &Interface_GTool::get_type_name, "None");
cls_Interface_GTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_GTool::get_type_descriptor, "None");
cls_Interface_GTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_GTool::*)() const) &Interface_GTool::DynamicType, "None");

// Enums

}