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
#include <TopoDSToStep_Root.hxx>
#include <Standard.hxx>
#include <TopoDS_Shell.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TopoDS_Solid.hxx>
#include <StepShape_ManifoldSolidBrep.hxx>
#include <TopoDSToStep_MakeManifoldSolidBrep.hxx>

void bind_TopoDSToStep_MakeManifoldSolidBrep(py::module &mod){

py::class_<TopoDSToStep_MakeManifoldSolidBrep, std::unique_ptr<TopoDSToStep_MakeManifoldSolidBrep>, TopoDSToStep_Root> cls_TopoDSToStep_MakeManifoldSolidBrep(mod, "TopoDSToStep_MakeManifoldSolidBrep", "This class implements the mapping between classes Shell or Solid from TopoDS and ManifoldSolidBrep from StepShape. All the topology and geometry comprised into the shell or the solid are taken into account and translated.");

// Constructors
cls_TopoDSToStep_MakeManifoldSolidBrep.def(py::init<const TopoDS_Shell &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));
cls_TopoDSToStep_MakeManifoldSolidBrep.def(py::init<const TopoDS_Solid &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));

// Fields

// Methods
// cls_TopoDSToStep_MakeManifoldSolidBrep.def_static("operator new_", (void * (*)(size_t)) &TopoDSToStep_MakeManifoldSolidBrep::operator new, "None", py::arg("theSize"));
// cls_TopoDSToStep_MakeManifoldSolidBrep.def_static("operator delete_", (void (*)(void *)) &TopoDSToStep_MakeManifoldSolidBrep::operator delete, "None", py::arg("theAddress"));
// cls_TopoDSToStep_MakeManifoldSolidBrep.def_static("operator new[]_", (void * (*)(size_t)) &TopoDSToStep_MakeManifoldSolidBrep::operator new[], "None", py::arg("theSize"));
// cls_TopoDSToStep_MakeManifoldSolidBrep.def_static("operator delete[]_", (void (*)(void *)) &TopoDSToStep_MakeManifoldSolidBrep::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDSToStep_MakeManifoldSolidBrep.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDSToStep_MakeManifoldSolidBrep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDSToStep_MakeManifoldSolidBrep.def_static("operator delete_", (void (*)(void *, void *)) &TopoDSToStep_MakeManifoldSolidBrep::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDSToStep_MakeManifoldSolidBrep.def("Value", (const opencascade::handle<StepShape_ManifoldSolidBrep> & (TopoDSToStep_MakeManifoldSolidBrep::*)() const) &TopoDSToStep_MakeManifoldSolidBrep::Value, "None");

// Enums

}