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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <IGESData_Protocol.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_SpecificLib.hxx>
#include <IGESData_IGESDumper.hxx>

void bind_IGESData_IGESDumper(py::module &mod){

py::class_<IGESData_IGESDumper, std::unique_ptr<IGESData_IGESDumper>> cls_IGESData_IGESDumper(mod, "IGESData_IGESDumper", "Provides a way to obtain a clear Dump of an IGESEntity (distinct from normalized output). It works with tools attached to Entities, as for normalized Reade and Write");

// Constructors
cls_IGESData_IGESDumper.def(py::init<const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &>(), py::arg("model"), py::arg("protocol"));

// Fields

// Methods
// cls_IGESData_IGESDumper.def_static("operator new_", (void * (*)(size_t)) &IGESData_IGESDumper::operator new, "None", py::arg("theSize"));
// cls_IGESData_IGESDumper.def_static("operator delete_", (void (*)(void *)) &IGESData_IGESDumper::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_IGESDumper.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_IGESDumper::operator new[], "None", py::arg("theSize"));
// cls_IGESData_IGESDumper.def_static("operator delete[]_", (void (*)(void *)) &IGESData_IGESDumper::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_IGESDumper.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_IGESDumper::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_IGESDumper.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_IGESDumper::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_IGESDumper.def("PrintDNum", (void (IGESData_IGESDumper::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESDumper::PrintDNum, "Prints onto an output, the 'Number of Directory Entry' which corresponds to an IGESEntity in the IGESModel, under the form 'D#nnn' (a Null Handle gives D#0)", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESDumper.def("PrintShort", (void (IGESData_IGESDumper::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESDumper::PrintShort, "Prints onto an output, the 'Number of Directory Entry' (see PrintDNum) plus IGES Type and Form Numbers, which gives 'D#nnn Type nnn Form nnn'", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESDumper.def("Dump", [](IGESData_IGESDumper &self, const opencascade::handle<IGESData_IGESEntity> & a0, const opencascade::handle<Message_Messenger> & a1, const Standard_Integer a2) -> void { return self.Dump(a0, a1, a2); });
cls_IGESData_IGESDumper.def("Dump", (void (IGESData_IGESDumper::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer, const Standard_Integer) const) &IGESData_IGESDumper::Dump, "None", py::arg("ent"), py::arg("S"), py::arg("own"), py::arg("attached"));
cls_IGESData_IGESDumper.def("OwnDump", (void (IGESData_IGESDumper::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESData_IGESDumper::OwnDump, "Specific Dump for each IGES Entity, call by Dump (just above) <own> is the parameter <own> from Dump", py::arg("ent"), py::arg("S"), py::arg("own"));

// Enums

}