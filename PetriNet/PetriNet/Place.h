#pragma once

class Place
{
public:
	Place() = default;
	Place(size_t startCount)
		: m_markers(startCount) {}

	size_t GetMarkers() const { return m_markers; }
	bool EnoughMarkers(size_t count) const { return m_markers >= count; }
	void AddMarkers(size_t count) { m_markers += count; }
	void RemoveMarkers(size_t count) { m_markers -= count; }

private:
	size_t m_markers;
};