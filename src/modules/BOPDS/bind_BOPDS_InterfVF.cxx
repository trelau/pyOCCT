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
#include <BOPDS_Interf.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>

void bind_BOPDS_InterfVF(py::module &mod){

py::class_<BOPDS_InterfVF, std::unique_ptr<BOPDS_InterfVF, Deleter<BOPDS_InterfVF>>, BOPDS_Interf> cls_BOPDS_InterfVF(mod, "BOPDS_InterfVF", "The class BOPDS_InterfVF is is to store the information about the interference of the type vertex/face");

// Constructors
cls_BOPDS_InterfVF.def(py::init<>());
cls_BOPDS_InterfVF.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
cls_BOPDS_InterfVF.def("SetUV", (void (BOPDS_InterfVF::*)(const Standard_Real, const Standard_Real)) &BOPDS_InterfVF::SetUV, "Modifier Sets the value of parameters of the point of the vertex on the surface of of the face", py::arg("theU"), py::arg("theV"));
cls_BOPDS_InterfVF.def("UV", [](BOPDS_InterfVF &self, Standard_Real & theU, Standard_Real & theV){ self.UV(theU, theV); return std::tuple<Standard_Real &, Standard_Real &>(theU, theV); }, "Selector Returns the value of parameters of the point of the vertex on the surface of of the face", py::arg("theU"), py::arg("theV"));

// Enums

}