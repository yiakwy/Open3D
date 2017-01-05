// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2015 Qianyi Zhou <Qianyi.Zhou@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include <thread>
#include <Core/Core.h>
#include <IO/IO.h>
#include <Visualization/Visualization.h>

namespace three {

class AlignmentSession : public IJsonConvertible
{
public:
	bool ConvertToJsonValue(Json::Value &value) const override;
	bool ConvertFromJsonValue(const Json::Value &value) override;

public:
	std::shared_ptr<PointCloud> source_ptr_;	// Original source pointcloud
	std::shared_ptr<PointCloud> target_ptr_;	// Original target pointcloud
	std::vector<size_t> source_indices_;	// Manually annotated point indices
	std::vector<size_t> target_indices_;	// Manually annotated point indices
	Eigen::Matrix4d transformation_;	// Current alignment result
	double voxel_size_ = -1.0;
	bool with_scaling_ = true;
};

}		// namespace three