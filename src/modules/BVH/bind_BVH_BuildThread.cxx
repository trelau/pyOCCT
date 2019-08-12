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
#include <BVH_BuildThread.hxx>
#include <BVH_BuildQueue.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_Thread.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_BVH_BuildThread(py::module &mod){

py::class_<BVH_BuildThread, opencascade::handle<BVH_BuildThread>, Standard_Transient> cls_BVH_BuildThread(mod, "BVH_BuildThread", "Wrapper for BVH build thread.");

// Constructors
cls_BVH_BuildThread.def(py::init<BVH_BuildTool &, BVH_BuildQueue &>(), py::arg("theBuildTool"), py::arg("theBuildQueue"));

// Fields

// Methods
cls_BVH_BuildThread.def("Run", (void (BVH_BuildThread::*)()) &BVH_BuildThread::Run, "Starts execution of BVH build thread.");
cls_BVH_BuildThread.def("Wait", (void (BVH_BuildThread::*)()) &BVH_BuildThread::Wait, "Waits till the thread finishes execution.");
cls_BVH_BuildThread.def_static("get_type_name_", (const char * (*)()) &BVH_BuildThread::get_type_name, "None");
cls_BVH_BuildThread.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_BuildThread::get_type_descriptor, "None");
cls_BVH_BuildThread.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_BuildThread::*)() const) &BVH_BuildThread::DynamicType, "None");

// Enums

}