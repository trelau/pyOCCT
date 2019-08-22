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
#include <Standard_TypeDef.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_Mutex.hxx>
#include <BVH_BuildQueue.hxx>

void bind_BVH_BuildQueue(py::module &mod){

py::class_<BVH_BuildQueue> cls_BVH_BuildQueue(mod, "BVH_BuildQueue", "Command-queue for parallel building of BVH nodes.");

// Constructors
cls_BVH_BuildQueue.def(py::init<>());

// Fields

// Methods
cls_BVH_BuildQueue.def("Size", (Standard_Integer (BVH_BuildQueue::*)()) &BVH_BuildQueue::Size, "Returns current size of BVH build queue.");
cls_BVH_BuildQueue.def("Enqueue", (void (BVH_BuildQueue::*)(const Standard_Integer &)) &BVH_BuildQueue::Enqueue, "Enqueues new work-item onto BVH build queue.", py::arg("theNode"));
cls_BVH_BuildQueue.def("Fetch", [](BVH_BuildQueue &self, Standard_Boolean & wasBusy){ Standard_Integer rv = self.Fetch(wasBusy); return std::tuple<Standard_Integer, Standard_Boolean &>(rv, wasBusy); }, "Fetches first work-item from BVH build queue.", py::arg("wasBusy"));
cls_BVH_BuildQueue.def("HasBusyThreads", (Standard_Boolean (BVH_BuildQueue::*)()) &BVH_BuildQueue::HasBusyThreads, "Checks if there are active build threads.");

// Enums

}