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
#include <OpenGl_HaltonSampler.hxx>

void bind_OpenGl_HaltonSampler(py::module &mod){

py::class_<OpenGl_HaltonSampler, std::unique_ptr<OpenGl_HaltonSampler, Deleter<OpenGl_HaltonSampler>>> cls_OpenGl_HaltonSampler(mod, "OpenGl_HaltonSampler", "Compute points of the Halton sequence with with digit-permutations for different bases.");

// Constructors

// Fields

// Methods
cls_OpenGl_HaltonSampler.def_static("get_num_dimensions_", (unsigned int (*)()) &OpenGl_HaltonSampler::get_num_dimensions, "Return the number of supported dimensions.");
cls_OpenGl_HaltonSampler.def("initFaure", (void (OpenGl_HaltonSampler::*)()) &OpenGl_HaltonSampler::initFaure, "Init the permutation arrays using Faure-permutations. Alternatively, initRandom() can be called before the sampling functionality can be used.");
cls_OpenGl_HaltonSampler.def("sample", (float (OpenGl_HaltonSampler::*)(unsigned int, unsigned int) const) &OpenGl_HaltonSampler::sample, "Return the Halton sample for the given dimension (component) and index. The client must have called initRandom or initFaure() at least once before. dimension must be smaller than the value returned by get_num_dimensions().", py::arg("theDimension"), py::arg("theIndex"));

// Enums

}