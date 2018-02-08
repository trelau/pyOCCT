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

#include <LocalTraceBufferPool.hxx>
#include <BasicsGenericDestructor.hxx>

PYBIND11_MODULE(LocalTraceBufferPool, mod) {

	// IMPORT
	py::module::import("OCCT.BasicsGenericDestructor");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\LocalTraceBufferPool.hxx
	py::class_<LocalTrace_TraceInfo, std::unique_ptr<LocalTrace_TraceInfo, Deleter<LocalTrace_TraceInfo>>> cls_LocalTrace_TraceInfo(mod, "LocalTrace_TraceInfo", "None");
	cls_LocalTrace_TraceInfo.def(py::init<>());

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\LocalTraceBufferPool.hxx
	py::class_<LocalTraceBufferPool, std::unique_ptr<LocalTraceBufferPool, py::nodelete>, PROTECTED_DELETE> cls_LocalTraceBufferPool(mod, "LocalTraceBufferPool", "None");
	cls_LocalTraceBufferPool.def_static("instance_", (LocalTraceBufferPool * (*)()) &LocalTraceBufferPool::instance, "None");
	cls_LocalTraceBufferPool.def("insert", (int (LocalTraceBufferPool::*)(int, const char *)) &LocalTraceBufferPool::insert, "None", py::arg("traceType"), py::arg("msg"));
	cls_LocalTraceBufferPool.def("retrieve", (int (LocalTraceBufferPool::*)(LocalTrace_TraceInfo &)) &LocalTraceBufferPool::retrieve, "None", py::arg("aTrace"));
	cls_LocalTraceBufferPool.def("toCollect", (unsigned long (LocalTraceBufferPool::*)()) &LocalTraceBufferPool::toCollect, "None");


}
